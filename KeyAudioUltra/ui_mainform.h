/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QWidget *left_widget;
    QWidget *verticalLayoutWidget;
    QFormLayout *left_formLayout;
    QLabel *inputDeviceLabel;
    QLineEdit *inputDeviceEdit;
    QLabel *audioCodecLabel;
    QLineEdit *audioCodecEdit;
    QLabel *fileContainerLabel;
    QLineEdit *fileContainerEdit;
    QLabel *sampleRateLabel;
    QLineEdit *sampleRateEdit;
    QLabel *channelLabel;
    QLineEdit *channelsEdit;
    QWidget *widget;
    QWidget *empty_widget;
    QFrame *line;
    QWidget *top_widget;
    QTabWidget *tabWidget;
    QWidget *audioTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *waveVerticalLayout;
    QWidget *wavTab;
    QWidget *mp3Tab;
    QWidget *right_widget;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout_left;
    QGroupBox *groupBox;
    QRadioButton *qualityRadioButton;
    QRadioButton *bitrateRadioButton;
    QWidget *widget_4;
    QSlider *volumeSlider;
    QLabel *VolumeLabel;
    QWidget *widget_2;
    QFrame *line_2;
    QWidget *widget_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *levelsLayout;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuExit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QStringLiteral("MainForm"));
        MainForm->resize(1024, 725);
        actionClose = new QAction(MainForm);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionAbout = new QAction(MainForm);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        left_widget = new QWidget(centralWidget);
        left_widget->setObjectName(QStringLiteral("left_widget"));
        verticalLayoutWidget = new QWidget(left_widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 461, 207));
        left_formLayout = new QFormLayout(verticalLayoutWidget);
        left_formLayout->setSpacing(6);
        left_formLayout->setContentsMargins(11, 11, 11, 11);
        left_formLayout->setObjectName(QStringLiteral("left_formLayout"));
        left_formLayout->setContentsMargins(0, 0, 0, 0);
        inputDeviceLabel = new QLabel(verticalLayoutWidget);
        inputDeviceLabel->setObjectName(QStringLiteral("inputDeviceLabel"));

        left_formLayout->setWidget(0, QFormLayout::LabelRole, inputDeviceLabel);

        inputDeviceEdit = new QLineEdit(verticalLayoutWidget);
        inputDeviceEdit->setObjectName(QStringLiteral("inputDeviceEdit"));

        left_formLayout->setWidget(0, QFormLayout::FieldRole, inputDeviceEdit);

        audioCodecLabel = new QLabel(verticalLayoutWidget);
        audioCodecLabel->setObjectName(QStringLiteral("audioCodecLabel"));

        left_formLayout->setWidget(1, QFormLayout::LabelRole, audioCodecLabel);

        audioCodecEdit = new QLineEdit(verticalLayoutWidget);
        audioCodecEdit->setObjectName(QStringLiteral("audioCodecEdit"));

        left_formLayout->setWidget(1, QFormLayout::FieldRole, audioCodecEdit);

        fileContainerLabel = new QLabel(verticalLayoutWidget);
        fileContainerLabel->setObjectName(QStringLiteral("fileContainerLabel"));

        left_formLayout->setWidget(2, QFormLayout::LabelRole, fileContainerLabel);

        fileContainerEdit = new QLineEdit(verticalLayoutWidget);
        fileContainerEdit->setObjectName(QStringLiteral("fileContainerEdit"));

        left_formLayout->setWidget(2, QFormLayout::FieldRole, fileContainerEdit);

        sampleRateLabel = new QLabel(verticalLayoutWidget);
        sampleRateLabel->setObjectName(QStringLiteral("sampleRateLabel"));

        left_formLayout->setWidget(3, QFormLayout::LabelRole, sampleRateLabel);

        sampleRateEdit = new QLineEdit(verticalLayoutWidget);
        sampleRateEdit->setObjectName(QStringLiteral("sampleRateEdit"));

        left_formLayout->setWidget(3, QFormLayout::FieldRole, sampleRateEdit);

        channelLabel = new QLabel(verticalLayoutWidget);
        channelLabel->setObjectName(QStringLiteral("channelLabel"));

        left_formLayout->setWidget(4, QFormLayout::LabelRole, channelLabel);

        channelsEdit = new QLineEdit(verticalLayoutWidget);
        channelsEdit->setObjectName(QStringLiteral("channelsEdit"));

        left_formLayout->setWidget(4, QFormLayout::FieldRole, channelsEdit);

        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(100, 40));

        left_formLayout->setWidget(5, QFormLayout::LabelRole, widget);

        empty_widget = new QWidget(verticalLayoutWidget);
        empty_widget->setObjectName(QStringLiteral("empty_widget"));
        empty_widget->setMinimumSize(QSize(200, 40));
        line = new QFrame(empty_widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 10, 358, 3));
        line->setMinimumSize(QSize(200, 2));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);

        left_formLayout->setWidget(5, QFormLayout::FieldRole, empty_widget);


        gridLayout->addWidget(left_widget, 1, 0, 1, 1);

        top_widget = new QWidget(centralWidget);
        top_widget->setObjectName(QStringLiteral("top_widget"));
        tabWidget = new QTabWidget(top_widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 991, 331));
        audioTab = new QWidget();
        audioTab->setObjectName(QStringLiteral("audioTab"));
        verticalLayoutWidget_2 = new QWidget(audioTab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(4, 4, 981, 291));
        waveVerticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        waveVerticalLayout->setSpacing(6);
        waveVerticalLayout->setContentsMargins(11, 11, 11, 11);
        waveVerticalLayout->setObjectName(QStringLiteral("waveVerticalLayout"));
        waveVerticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(audioTab, QString());
        wavTab = new QWidget();
        wavTab->setObjectName(QStringLiteral("wavTab"));
        tabWidget->addTab(wavTab, QString());
        mp3Tab = new QWidget();
        mp3Tab->setObjectName(QStringLiteral("mp3Tab"));
        tabWidget->addTab(mp3Tab, QString());

        gridLayout->addWidget(top_widget, 0, 0, 1, 2);

        right_widget = new QWidget(centralWidget);
        right_widget->setObjectName(QStringLiteral("right_widget"));
        formLayoutWidget = new QWidget(right_widget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 0, 481, 201));
        gridLayout_left = new QGridLayout(formLayoutWidget);
        gridLayout_left->setSpacing(6);
        gridLayout_left->setContentsMargins(11, 11, 11, 11);
        gridLayout_left->setObjectName(QStringLiteral("gridLayout_left"));
        gridLayout_left->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_left->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(formLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(300, 120));
        qualityRadioButton = new QRadioButton(groupBox);
        qualityRadioButton->setObjectName(QStringLiteral("qualityRadioButton"));
        qualityRadioButton->setGeometry(QRect(21, 41, 112, 23));
        bitrateRadioButton = new QRadioButton(groupBox);
        bitrateRadioButton->setObjectName(QStringLiteral("bitrateRadioButton"));
        bitrateRadioButton->setGeometry(QRect(21, 78, 112, 23));

        gridLayout_left->addWidget(groupBox, 0, 0, 1, 1);

        widget_4 = new QWidget(formLayoutWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        volumeSlider = new QSlider(widget_4);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(10, 10, 31, 101));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Vertical);
        VolumeLabel = new QLabel(widget_4);
        VolumeLabel->setObjectName(QStringLiteral("VolumeLabel"));
        VolumeLabel->setGeometry(QRect(40, 50, 67, 17));

        gridLayout_left->addWidget(widget_4, 0, 1, 1, 1);

        widget_2 = new QWidget(formLayoutWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(300, 40));
        line_2 = new QFrame(widget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-90, 10, 461, 20));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_left->addWidget(widget_2, 1, 0, 1, 1);

        widget_3 = new QWidget(formLayoutWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayoutWidget = new QWidget(widget_3);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 171, 71));
        levelsLayout = new QHBoxLayout(horizontalLayoutWidget);
        levelsLayout->setSpacing(6);
        levelsLayout->setContentsMargins(11, 11, 11, 11);
        levelsLayout->setObjectName(QStringLiteral("levelsLayout"));
        levelsLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_left->addWidget(widget_3, 1, 1, 1, 1);


        gridLayout->addWidget(right_widget, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainForm->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainForm);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainForm->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainForm->setMenuBar(menuBar);

        menuBar->addAction(menuExit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuExit->addAction(actionClose);
        menuExit->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Receiver tool", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainForm", "Close(&C)", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainForm", "About(&A)", Q_NULLPTR));
        inputDeviceLabel->setText(QApplication::translate("MainForm", "Input Device:", Q_NULLPTR));
        audioCodecLabel->setText(QApplication::translate("MainForm", "Audio Codec:", Q_NULLPTR));
        fileContainerLabel->setText(QApplication::translate("MainForm", "File Container", Q_NULLPTR));
        sampleRateLabel->setText(QApplication::translate("MainForm", "Sample Rate:", Q_NULLPTR));
        channelLabel->setText(QApplication::translate("MainForm", "Channels: ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(audioTab), QApplication::translate("MainForm", "Audio", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(wavTab), QApplication::translate("MainForm", "WAV", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(mp3Tab), QApplication::translate("MainForm", "MP3", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainForm", "Encoding Mode", Q_NULLPTR));
        qualityRadioButton->setText(QApplication::translate("MainForm", "Quality", Q_NULLPTR));
        bitrateRadioButton->setText(QApplication::translate("MainForm", "Bitrate", Q_NULLPTR));
        VolumeLabel->setText(QApplication::translate("MainForm", "Volume", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainForm", "toolBar", Q_NULLPTR));
        menuExit->setTitle(QApplication::translate("MainForm", "Exit(&E)", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainForm", "Help(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
