#include "AudioReceiver.h"
#include "MainForm.h"

#define DEBUG qDebug() << __FILE__ << __LINE__ << __FUNCTION__

//template <class T>
class MainForm;

AudioReceiver::AudioReceiver(QWidget *parent) : QWidget(parent), outputLocationSet(false)
{
    this->parent = (MainForm *)parent;

    audioRecorder = new QAudioRecorder(this);
    probe = new QAudioProbe();
    QObject::connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(processBuffer(QAudioBuffer)));
    probe->setSource(audioRecorder);

    int index;

    // scan audio devices
    foreach(const QString &device, audioRecorder->audioInputs()) {
        inputDeviceField = "default:";
    }

    // scan audio codecs
    foreach (const QString &codecName, audioRecorder->supportedAudioCodecs()) {
        audioCodecField = "Default";
    }

    // containers
    foreach (const QString &containerName, audioRecorder->supportedContainers()) {     
        if(containerName == "audio/x-wav") {
            // equal
            fileContainerField = containerName;
//            fileContainerField = "wav";
        }
    }


    // sample rate
    foreach(const int sampleRate, audioRecorder->supportedAudioSampleRates()) {
        DEBUG << QString(sampleRate);
    }
    sampleRateField = "Default";
    channelsField = "1";

//    format.setSampleSize(8);
//    format.setCodec("audio/wav");
//    format.setByteOrder(QAudioFormat::LittleEndian);
//    format.setSampleType(QAudioFormat::UnSignedInt);

    this->initObjectEvent();
}

AudioReceiver::~AudioReceiver() {
    releaseObjectEvent();
    if(!settings.isNull())
        delete &settings;
    delete audioRecorder;
    delete probe;
}

void AudioReceiver::initObjectEvent() {
    QObject::connect(audioRecorder, SIGNAL(durationChanged(qint64)),
                     this, SLOT(updateProgress(qint64)));
    QObject::connect(audioRecorder, SIGNAL(statusChanged(QMediaRecorder::Status)),
                     this, SLOT(updateStatus(QMediaRecorder::Status)));
    QObject::connect(audioRecorder, SIGNAL(stateChanged(QMediaRecorder::State)),
                     this, SLOT(onStateChanged(QMediaRecorder::State)));
    QObject::connect(audioRecorder, SIGNAL(error(QMediaRecorder::Error)),
                     this, SLOT(displayErrorMessage()));
}


void AudioReceiver::releaseObjectEvent() {
    QObject::disconnect(audioRecorder, SIGNAL(durationChanged(qint64)),
                     this, SLOT(updateProgress(qint64)));
    QObject::disconnect(audioRecorder, SIGNAL(statusChanged(QMediaRecorder::Status)),
                     this, SLOT(updateStatus(QMediaRecorder::Status)));
    QObject::disconnect(audioRecorder, SIGNAL(stateChanged(QMediaRecorder::State)),
                     this, SLOT(onStateChanged(QMediaRecorder::State)));
    QObject::disconnect(audioRecorder, SIGNAL(error(QMediaRecorder::Error)),
                     this, SLOT(displayErrorMessage()));
}

void AudioReceiver::startReceiveAudio() {
    audioRecorder->record();
}


void AudioReceiver::stopReceiveAudio() {
    audioRecorder->stop();
}

void AudioReceiver::pauseReceiveAudio() {
    audioRecorder->pause();
}


void AudioReceiver::processBuffer(const QAudioBuffer &buffer) {
    DEBUG << "processing:" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    if (audioLevels.count() != buffer.format().channelCount()) {
        qDeleteAll(audioLevels);
        audioLevels.clear();
        for (int i = 0; i < buffer.format().channelCount(); ++i) {
            AudioLevel *level = new AudioLevel(this);
            audioLevels.append(level);
            QHBoxLayout *levelsLayout = this->parent->getlevelsLayout();
            levelsLayout->addWidget(level);
        }
    }

    if (audioWaveForms.count() != buffer.format().channelCount()) {
        qDeleteAll(audioWaveForms);
        audioWaveForms.clear();
        for (int i = 0; i < buffer.format().channelCount(); ++i) {
            AudioWaveForm *waveForm = new AudioWaveForm(this->parent->getAudioWaveWidget(), i);
            waveForm->setStyleSheet("QWidget{background:#00BB11;}");
            audioWaveForms.append(waveForm);
            QLayout *waveLayout = this->parent->getAudioWaveLayout();
            waveLayout->addWidget(waveForm);
        }
    }

    qreal volume = audioRecorder->volume();
    QVector<qreal> levels = getBufferLevels(buffer);
    for(int i=0;i<levels.count();++i) {
        audioLevels.at(i)->setLevel(volume * levels.at(i));
        audioWaveForms.at(i)->updateLevel(volume *levels.at(i));
    }
}


void AudioReceiver::setOutputLocation() {

}


void AudioReceiver::togglePause() {
    if(audioRecorder->state() != QMediaRecorder::PausedState)
        audioRecorder->pause();
    else
        audioRecorder->record();
}


void AudioReceiver::toggleRecord() {

}


void AudioReceiver::updateStatus(QMediaRecorder::Status status) {
    DEBUG << status;
    QString statusInfo;
    switch(status) {

    case QMediaRecorder::RecordingStatus:
        DEBUG << tr("Receiver mic");
        break;
    case QMediaRecorder::PausedStatus:
        DEBUG << tr("Paused");
        break;
    case QMediaRecorder:: UnloadedStatus:
        break;
    case QMediaRecorder::LoadedStatus:
        DEBUG << tr("Stopped");
        break;
    default:
        break;

    }
}


void AudioReceiver::onStateChanged(QMediaRecorder::State state) {
    DEBUG << state;
}


void AudioReceiver::updateProgress(qint64 duration) {
    if(audioRecorder->error() != QMediaRecorder::NoError || duration < 1000) {
        return;
    }
}


void AudioReceiver::displayErrorMessage() {
    DEBUG << audioRecorder->errorString();
}


void AudioReceiver::onVolumeSliderValueChanged(int value) {
    qreal volume = value;
    volume /= 100;
    audioRecorder->setVolume(volume);
}


void AudioReceiver::clearAudioLevels() {
    for(int i=0;i<audioLevels.size();++i)
        audioLevels.at(i)->setLevel(0);
}

void AudioReceiver::setAudioCodec(QString codec) {
    settings.setCodec(codec);
    DEBUG << codec;
}

void AudioReceiver::setSampleRate(QString rate) {
    settings.setSampleRate(rate.toInt());
    DEBUG << rate;
}

void AudioReceiver::setChannelCount(QString channls) {
    settings.setChannelCount(channls.toInt());
    DEBUG << channls;
}

void AudioReceiver::setAudioInputDevice(QString device) {
    audioRecorder->setAudioInput(device);
    DEBUG << device;
}

void AudioReceiver::setBitRate(QString bitRate) {
    settings.setBitRate(bitRate.toInt());
    DEBUG << bitRate;
}

void AudioReceiver::setQuality(int volume) {
    settings.setQuality(QMultimedia::EncodingQuality(volume));
    DEBUG << volume;
}


void AudioReceiver::setEncodingMode(ConstantType mode) {
    if(mode == QualityEncoding) {
        settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
    }else if(mode == BitRateEncoding) {
        settings.setEncodingMode(QMultimedia::ConstantBitRateEncoding);
    }
}

void AudioReceiver::setEncodingSettingsConfig(QString container) {
    audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), container);
    DEBUG << container;
}

QString AudioReceiver::getFileContainer() {
    return this->fileContainerField;
}

QString AudioReceiver::getInputDevice() {
    return this->inputDeviceField;
}

QString AudioReceiver::getAudioCodec() {
    return this->audioCodecField;
}

QString AudioReceiver::getSampleRate() {
    return this->sampleRateField;
}

QString AudioReceiver::getChannels() {
    return this->channelsField;
}

qreal AudioReceiver::getPeakValue(const QAudioFormat &format) {
    if(!format.isValid())
        return qreal(0);

    if(format.codec() != "audio/pcm")
        return qreal(0);

    switch(format.sampleType()) {
    case QAudioFormat::Unknown:
        break;
    case QAudioFormat::Float:
        if(format.sampleSize() != 32)
            return qreal(0);
        return qreal(1.00003);
    case QAudioFormat::SignedInt:
        if(format.sampleSize() == 32)
            return qreal(INT_MAX);
        if(format.sampleSize() == 16)
            return qreal(SHRT_MAX);
        if(format.sampleSize() == 8)
            return qreal(CHAR_MAX);
        break;
    case QAudioFormat::UnSignedInt:
        if(format.sampleSize() == 32)
            return qreal(UINT_MAX);
        if(format.sampleSize() == 16)
            return qreal(USHRT_MAX);
        if(format.sampleSize() == 8)
            return qreal(UCHAR_MAX);
        break;
    }
    return qreal(0);
}

QVector<qreal> AudioReceiver::getBufferLevels(const QAudioBuffer &buffer) {
    QVector<qreal> values;

    if(!buffer.format().isValid() || buffer.format().byteOrder() != QAudioFormat::LittleEndian) {
        return values;
    }
    if(buffer.format().codec() != "audio/pcm") {
        return values;
    }
    int channelCount = buffer.format().channelCount();
    values.fill(0, channelCount);
    qreal peak_value = getPeakValue(buffer.format());
    if(qFuzzyCompare(peak_value, qreal(0)))
        return values;

    switch(buffer.format().sampleType()) {
    case QAudioFormat::Unknown:
    case QAudioFormat::UnSignedInt:
        if(buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<quint32>(), buffer.frameCount(), channelCount);
        if(buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<quint16>(), buffer.frameCount(), channelCount);
        if(buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<quint8>(), buffer.frameCount(), channelCount);

        for(int i=0;i<values.size(); ++i) {
            values[i] = qAbs(values.at(i) - peak_value / 2) / (peak_value / 2);
        }

        break;
    case QAudioFormat::Float:
        if(buffer.format().sampleSize() == 32) {
            values = getBufferLevels(buffer.constData<float>(), buffer.frameCount(), channelCount);
            for(int i = 0; i < values.size(); ++i)
                values[i] /= peak_value;
        }
        break;
    case QAudioFormat::SignedInt:
        if(buffer.format().sampleSize() == 32)
            values = getBufferLevels(buffer.constData<qint32>(), buffer.frameCount(), channelCount);
        if(buffer.format().sampleSize() == 16)
            values = getBufferLevels(buffer.constData<qint16>(), buffer.frameCount(), channelCount);
        if(buffer.format().sampleSize() == 8)
            values = getBufferLevels(buffer.constData<qint8>(), buffer.frameCount(), channelCount);
        for(int i=0;i < values.size(); ++i)
            values[i] /= peak_value;
        break;
    }
    return values;
}


template <class T>
QVector<qreal> AudioReceiver::getBufferLevels(const T *buffer, int frames, int channels)
{
    QVector<qreal> max_values;
    max_values.fill(0, channels);

    for (int i = 0; i < frames; ++i) {
        for (int j = 0; j < channels; ++j) {
            qreal value = qAbs(qreal(buffer[i * channels + j]));
            if (value > max_values.at(j))
                max_values.replace(j, value);
        }
    }

    return max_values;
}
