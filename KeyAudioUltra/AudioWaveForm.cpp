#include "AudioWaveForm.h"

#define DEFAULT_WAVE_FORM_HEIGHT 60
#define DEFAULT_WAVE_FORM_WIDTH 300

AudioWaveForm::AudioWaveForm(QWidget *parent) : QWidget(parent)
{
    setMinimumHeight(DEFAULT_WAVE_FORM_HEIGHT);
    number = 0;
}

AudioWaveForm::AudioWaveForm(QWidget *parent, int index) : QWidget(parent) {
    setMinimumHeight(DEFAULT_WAVE_FORM_HEIGHT);
    setMinimumWidth(DEFAULT_WAVE_FORM_WIDTH);
    number = index;

    QColor color(QWidget::palette().color(QWidget::backgroundRole()));
    QString AudioWaveFormStyle("background-color:#68CAD3; border:2px;");
    AudioWaveFormStyle.arg(color.red()).arg(color.green()).arg(color.blue());
    this->setStyleSheet(AudioWaveFormStyle);
}


void AudioWaveForm::updateLevel(qreal level){
    while(m_levels.count() >= width()) {
        m_levels.removeFirst();
    }
    m_levels.append(level);
    update();
}

void AudioWaveForm::clearLevels() {
    while(!m_levels.isEmpty()) {
        m_levels.removeFirst();
    }
}

void AudioWaveForm::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    QColor paint;
    qreal level;
    qreal fractionalLevel;

    for(int i=0;i< m_levels.count();++i) {
        fractionalLevel = m_levels.at(i);
        if(fractionalLevel < 0.5) {
//            paint = QColor(0, 150, 35); // Green
            paint = QColor(255, 255, 255);
        }else if(fractionalLevel < 0.6) {
            paint = QColor(255, 212, 0); // Yellow
        }else if(fractionalLevel < 0.7) {
            paint = QColor(255, 144, 0); // Orange
        }else {
            paint = QColor(255, 0, 0); // Red
        }
        painter.setPen(QPen(paint, 1, Qt::SolidLine, Qt::RoundCap));
        level = fractionalLevel * height() * 1.3;
        if(number % 2 == 0)
            painter.drawLine(i, height(), i, height() - level);
        else
            painter.drawLine(i, level, i, 0);
    }
}
