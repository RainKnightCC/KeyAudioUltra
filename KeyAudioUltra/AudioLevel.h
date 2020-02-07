#ifndef AUDIOLEVEL_H
#define AUDIOLEVEL_H

#include <QWidget>
#include <QPainter>

class AudioLevel : public QWidget
{
    Q_OBJECT
public:
    explicit AudioLevel(QWidget *parent = nullptr);

    void setLevel(qreal level);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:

private:
    qreal m_level;
};

#endif // AUDIOLEVEL_H
