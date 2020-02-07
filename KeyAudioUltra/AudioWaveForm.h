#ifndef AUDIOWAVEFORM_H
#define AUDIOWAVEFORM_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class AudioWaveForm;
}

class AudioWaveForm : public QWidget
{
    Q_OBJECT
public:
    explicit AudioWaveForm(QWidget *parent = nullptr);
    explicit AudioWaveForm(QWidget *parent = nullptr, int index = 0);

    void updateLevel(qreal level);
    void clearLevels();

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:

private:
    int number;
    QList<qreal> m_levels;
};

#endif // AUDIOWAVEFORM_H
