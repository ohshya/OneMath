#include "SineWaveWidget.h"
#include <QPainter>
#include <cmath>

SineWaveWidget::SineWaveWidget(QWidget *parent)
    : QWidget(parent), xOffset(0)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SineWaveWidget::update);
    timer->start(10);

    setMinimumSize(800, 400);
}

SineWaveWidget::~SineWaveWidget()
{
    timer->stop();
    delete timer;
}

void SineWaveWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width();
    int height = this->height() / 1.2;
    int period = 600;

    QPointF lastPointSine;
    bool firstPointSine = true;

    QPointF lastPointCos;
    bool firstPointCos = true;

    for (int x = 0; x < width; x += 2)
    {

        double ajuste = (x + xOffset) * 2 * M_PI / period;
        double ySine = sin(ajuste) * (height / 4) + (height / 2);
        double yCos = cos(ajuste) * (height / 4.5) + (height / 2.5);

        QColor custom1(24, 49, 93);
        QPen bluePen(custom1);
        bluePen.setWidth(3);
        painter.setPen(bluePen);
        if (firstPointSine)
        {
            lastPointSine = QPointF(x, ySine);
            firstPointSine = false;
        }
        else
        {
            painter.drawLine(lastPointSine, QPointF(x, ySine));
            lastPointSine = QPointF(x, ySine);
        }

        QColor custom2(253, 187, 20);
        QPen redPen(custom2);
        redPen.setWidth(3);
        painter.setPen(redPen);
        if (firstPointCos)
        {
            lastPointCos = QPointF(x, yCos);
            firstPointCos = false;
        }
        else
        {
            painter.drawLine(lastPointCos, QPointF(x, yCos));
            lastPointCos = QPointF(x, yCos);
        }
    }
}

void SineWaveWidget::update()
{
    xOffset += 1;
    repaint();
}
