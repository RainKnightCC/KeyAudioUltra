#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QToolButton>
#include <QPalette>
#include <QMessageBox>

#include "AudioWaveForm.h"
#include "AudioReceiver.h"
#include"globaldefine.h"

#include"MonitoreSafAPI.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();

public slots:
    void exitMenuEvent();
    void aboutMenuEvent();

    QHBoxLayout *getlevelsLayout();
    QLayout *getAudioWaveLayout();
    QWidget *getAudioWaveWidget();


    void toolBarExitEvent(bool status);
    void toolBarSaveEvent(bool status);
    void toolBarOpenEvent(bool status);

private:
    Ui::MainForm *ui;

    AudioReceiver *audioReceiver;

    void initWidgetStyleSheet();
    void initGroupBoxStyleSheet();
    void initLabelStyleSheet();
    void initMenuItemSignalSlotEvent();
    void initToolBarSignalSlotEvent();
    void initAudioDevice();
    void createToolbarItems();
    void setTabWidgetStyle();

    void dynamicInsertWaveForm();
};

#endif // MAINFORM_H
