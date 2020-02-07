#include "MainForm.h"
#include "ui_mainform.h"

#include <QComboBox>

#define FORM_WIDTH 1024
#define FORM_HEIGHT 768

#define DEBUG qDebug() << __FILE__ << __LINE__ << __FUNCTION__

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->menuBar->setStyleSheet(
                "QMenu::separator{height:1px;background:#222222;margin-left:10px;margin-right:10px;margin-top:1px;margin-bottom:1px;}"
                "QMenu{background-color:black;border:1px solid gray;color:white;padding:1px}"
                "QMenu::item{padding:2px 25px 2px 20px; border:1px solid transparent;}"
                "QMenu::item:disabled{color:#666666;}"
                );
    this->setFixedHeight(FORM_HEIGHT);
    this->setFixedWidth(FORM_WIDTH);
    ui->top_widget->setFixedHeight(350);
//    ui->top_widget->setStyleSheet("QWidget:{background:#483D9A}");
//    ui->left_widget->setStyleSheet("QWidget:{background:#483D9A}");
//    ui->right_widget->setStyleSheet("QWidget:{background:#483D9A}");
    ui->toolBar->setFixedHeight(58);
    ui->toolBar->setFixedWidth(FORM_WIDTH);

//    this->initWidgetStyleSheet();
    this->initGroupBoxStyleSheet();
    this->initLabelStyleSheet();
    this->initMenuItemSignalSlotEvent();
    this->createToolbarItems();
    this->setTabWidgetStyle();
    this->dynamicInsertWaveForm();
    this->initAudioDevice();

}

void MainForm::setTabWidgetStyle() {
//    ui->tabWidget->setStyleSheet("QTabWidget{background-color:beige}");
    ui->tabWidget->setStyleSheet(
                "QTabWidget{background:#f0f0f0;}"
                "QTabWidget::pane{border-top:2px solid #C2C7CB;position:absolute;border-color: #cccccc}"
                "QTabWidget::tab-bar{alignment:center;}"
                "QTabBar::tab{color:black;font:16px 'DejaVu Serif';min-width:120px;min-height:40px;}"
                "QTabBar::tab:first:selected{background:#7196bc;}"
                "QTabBar::tab:first{background:#abc2d8;}"
                "QTabBar::tab:middle:selected{background:#adb8c2;}"
                "QTabBar::tab:middle{background:#98a6b3;}"
                "QTabBar::tab:last:selected{background:#969791;}"
                "QTabBar::tab:last{background:#b5b5b5;}"
                "QTabBar::tab:hover{background: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0#fafafa,stop:0.4 #f4f4f4,stop:0.5 #e7e7e7, stop:1.0 #fafafa);}"
                );
}

void MainForm::createToolbarItems() {
    /* Open Button */
    QToolButton *openBtnItem = new QToolButton();
    QObject::connect(openBtnItem, SIGNAL(clicked(bool)), this, SLOT(toolBarOpenEvent(bool)));
    openBtnItem->setIcon(QIcon(":/smg/resource/Open_file.png"));
    openBtnItem->setText("Open");
    openBtnItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    openBtnItem->setFont(QFont("DejaVu Serif", 12));
//    openBtnItem->setGeometry(0, 0, 5, 5);
    openBtnItem->setFixedWidth(100);
    openBtnItem->setFixedHeight(50);
    ui->toolBar->addWidget(openBtnItem);

    /* Save Button */
    QToolButton *saveBtnItem = new QToolButton();
    QObject::connect(saveBtnItem, SIGNAL(clicked(bool)), this, SLOT(toolBarSaveEvent(bool)));
    saveBtnItem->setIcon(QIcon(":/smg/resource/Save.png"));
    saveBtnItem->setText("Save");
    saveBtnItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    saveBtnItem->setFont(QFont("DejaVu Serif", 12));
//    saveBtnItem->setGeometry(0, 0, 5, 5);
    saveBtnItem->setFixedWidth(100);
    saveBtnItem->setFixedHeight(50);
    ui->toolBar->addWidget(saveBtnItem);

    /* Exit Button */
    QToolButton *exitBtnItem = new QToolButton();
    QObject::connect(exitBtnItem, SIGNAL(clicked(bool)), this, SLOT(toolBarExitEvent(bool)));
    exitBtnItem->setIcon(QIcon(":/smg/resource/Exit_logout.png"));
    exitBtnItem->setText("Exit");
    exitBtnItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    exitBtnItem->setFont(QFont("DejaVu Serif", 12));
//    exitBtnItem->setGeometry(0, 0, 5, 5);
    exitBtnItem->setFixedWidth(100);
    exitBtnItem->setFixedHeight(50);
    ui->toolBar->addWidget(exitBtnItem);
    ui->toolBar->addSeparator();
    ui->toolBar->setStyleSheet(
                "QToolBar{background-color:beige}"
                );
}

MainForm::~MainForm()
{
    QMenu::disconnect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(exitMenuEvent()));
    delete audioReceiver;
    delete ui;
}

void MainForm::dynamicInsertWaveForm() {
//    AudioWaveForm *tabWaveForm = new AudioWaveForm(this, 0);
//    ui->tabWidget->addTab(tabWaveForm, "Audio");
//    tabWaveForm->setFixedHeight(150);
//    tabWaveForm->setFixedWidth(300);
}


static QVariant boxValue(const QLineEdit *box)
{
    QVariant output(box->text());
    return output;
}

void MainForm::initAudioDevice() {
//    audioReceiver = new AudioReceiver(this);

//    int index  = ui->tabWidget->addTab(audioReceiver, "Audio");
//    audioReceiver->setFixedHeight(150);
//    audioReceiver->setFixedWidth(300);

//    QWidget *lwidget = new QWidget();
//    int index  = ui->tabWidget->addTab(lwidget, "Audio");
//    lwidget->setFixedHeight(150);
//    lwidget->setFixedWidth(300);
//    lwidget->setStyleSheet("QWidget{background:#334578;}");
    ui->tabWidget->setFixedHeight(500);
    ui->audioTab->setStyleSheet("QWidget{background:#334578;}");
    ui->audioTab->setFixedHeight(500);

    audioReceiver = new AudioReceiver(this);

//    QHBoxLayout *waveLayout = new QHBoxLayout();
//    ui->tabWidget->widget(index)->layout()->

    ui->fileContainerEdit->setText(audioReceiver->getFileContainer());
    ui->inputDeviceEdit->setText(audioReceiver->getInputDevice());
    ui->audioCodecEdit->setText(audioReceiver->getAudioCodec());
    ui->sampleRateEdit->setText(audioReceiver->getSampleRate());
    ui->channelsEdit->setText(audioReceiver->getChannels());

    ui->volumeSlider->setRange(0, int(QMultimedia::VeryHighQuality));
    ui->volumeSlider->setValue(int(QMultimedia::VeryHighQuality));
    ui->qualityRadioButton->setChecked(true);
    ui->bitrateRadioButton->setChecked(false);

    // setting for audio hardware
//    audioReceiver->setAudioInputDevice(ui->inputDeviceEdit->text());
//    audioReceiver->setAudioCodec(ui->audioCodecEdit->text());
//    audioReceiver->setSampleRate(ui->sampleRateEdit->text());
//    audioReceiver->setChannelCount(ui->channelsEdit->text());
//    audioReceiver->setQuality(ui->volumeSlider->value());
//    audioReceiver->setBitRate("16000");

//    if(ui->qualityRadioButton->isChecked() == true) {
//        audioReceiver->setEncodingMode(QualityEncoding);
//    }else if(ui->bitrateRadioButton->isChecked() == true){
//        audioReceiver->setEncodingMode(BitRateEncoding);
//    }

//    audioReceiver->setEncodingSettingsConfig(ui->fileContainerEdit->text());
//    audioReceiver->startReceiveAudio();


    audioReceiver->setAudioInputDevice(boxValue(ui->inputDeviceEdit).toString());
    qDebug()<< boxValue(ui->inputDeviceEdit).toString();
    QAudioEncoderSettings lsettings;
    lsettings.setCodec(boxValue(ui->audioCodecEdit).toString());
    qDebug()<< boxValue(ui->audioCodecEdit).toString();
    lsettings.setSampleRate(boxValue(ui->sampleRateEdit).toInt());
    qDebug()<< boxValue(ui->sampleRateEdit).toInt();
    lsettings.setBitRate(QString("16000").toInt());
    qDebug()<< QString("16000").toInt();
    lsettings.setChannelCount(boxValue(ui->channelsEdit).toInt());
    qDebug()<< boxValue(ui->channelsEdit).toInt();
    lsettings.setQuality(QMultimedia::EncodingQuality(ui->volumeSlider->value()));
    lsettings.setEncodingMode(ui->qualityRadioButton->isChecked() ?
                             QMultimedia::ConstantQualityEncoding :
                             QMultimedia::ConstantBitRateEncoding);

    QString container = boxValue(ui->fileContainerEdit).toString();
    qDebug()<< boxValue(ui->fileContainerEdit).toString();
    audioReceiver->setEncodingSettingsConfig(container);
    audioReceiver->startReceiveAudio();

}

void MainForm::initToolBarSignalSlotEvent() {
}


void MainForm::initMenuItemSignalSlotEvent() {
    QMenu::connect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(exitMenuEvent()));
    QMenu::connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(aboutMenuEvent()));
}

void MainForm::initWidgetStyleSheet() {

    QColor color(QWidget::palette().color(QWidget::backgroundRole()));
    QString TopStyle("background-color:#E3E3E3; border:0px;");
    QString LeftStyle("background-color:#E3E3E3; border:0px;");
    QString RightStyle("background-color:#E3E3E3; border:0px;");
    TopStyle.arg(color.red()).arg(color.green()).arg(color.blue());
    ui->top_widget->setStyleSheet(TopStyle);
    ui->left_widget->setStyleSheet(LeftStyle);
    ui->right_widget->setStyleSheet(RightStyle);
    ui->toolBar->setStyleSheet(TopStyle);
}

void MainForm::initGroupBoxStyleSheet() {
//    ui->groupBox->setStyleSheet(
//                "QGroupBox{background:#3A4A5A;}"
//                "QGroupBox{color:black;font:16px 'DejaVu Serif';}"
//                );
    ui->groupBox->setStyleSheet(
                "QGroupBox{color:black;font:16px 'DejaVu Serif';}"
                );

    ui->qualityRadioButton->setStyleSheet(
                "QRadioButton{color:black;font:16px 'DejaVu Serif';}"
                );
    ui->bitrateRadioButton->setStyleSheet(
                "QRadioButton{color:black;font:16px 'DejaVu Serif';}"
                "QRadioButton::indicator{width:15px;height:15px;}"
                );

}

void MainForm::initLabelStyleSheet() {
    ui->inputDeviceLabel->setStyleSheet(
                "QLabel{color:black;font:16px 'DejaVu Serif';}"
                );
    ui->audioCodecLabel->setStyleSheet(
                "QLabel{color:black;font:16px 'DejaVu Serif';}"
                );
    ui->fileContainerLabel->setStyleSheet(
                "QLabel{color:black;font:16px 'DejaVu Serif';}"
                );
    ui->sampleRateLabel->setStyleSheet(
                "QLabel{color:black;font:16px 'DejaVu Serif';}"
                );
    ui->channelLabel->setStyleSheet(
                "QLabel{color:black;font:16px 'DejaVu Serif';}"
                );
    ui->VolumeLabel->setStyleSheet(
                "QLabel{color:black;font:16px 'DejaVu Serif';}"
                );
}

QHBoxLayout *MainForm::getlevelsLayout() {
    return ui->levelsLayout;
}

QLayout *MainForm::getAudioWaveLayout() {
//    QWidget *widget = ui->tabWidget->widget(index);
//    return widget;
    return ui->waveVerticalLayout;
}

QWidget *MainForm::getAudioWaveWidget() {
    return ui->audioTab;
}

void MainForm::exitMenuEvent() {
    audioReceiver->stopReceiveAudio();
    this->close();
}

void MainForm::aboutMenuEvent() {
    QMessageBox::information(
        this,
        tr("Receiver tool"),
        tr("Current version : v1.0.0"),
        0x00000400
    );
}


void MainForm::toolBarExitEvent(bool status) {
    audioReceiver->stopReceiveAudio();
    this->close();
}

void MainForm::toolBarSaveEvent(bool status) {

}

void MainForm::toolBarOpenEvent(bool status) {

}
