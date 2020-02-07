#include "AudioLevel.h"

AudioLevel::AudioLevel(QWidget *parent) : QWidget(parent)
{
    this->setMinimumWidth(15);
    this->setMaximumWidth(50);
}



void AudioLevel::setLevel(qreal level) {
    if(m_level != level) {
        m_level = level;
        update();
    }
}


void AudioLevel::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    qreal level = m_level * height();
    if(level <= 50)
        painter.fillRect(0 , height() - level, width(), height(), Qt::darkGreen);
    else
        painter.fillRect(0 , height() - level, width(), height(), Qt::darkRed);

    painter.fillRect(0, height() - level, width(), 0, Qt::black);
}
