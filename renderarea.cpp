#include "renderarea.h"
#include <QPoint>
#include <QPainter>
#include <QPen>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);

    setAutoFillBackground(true);
    setPalette(Pal);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(300, 300);
}

QSize RenderArea::sizeHint() const
{
    return QSize(640, 480);
}

void RenderArea::setPaintMatrix(int numIters, float *pointsMatrix)
{
    numIterations = numIters;
    std::copy(pointsMatrix, pointsMatrix + 30000, &mandelbrotSet[0][0]);

    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    //painter.translate(width()/2, height()/2);
    for (int i = 0; i < 10000; i++)
    {
        QColor color((trunc(200*mandelbrotSet[i][2]/numIterations)), (trunc(255*mandelbrotSet[i][2]/numIterations)),
                (trunc(100*mandelbrotSet[i][2]/numIterations)));
        QPen pen (QPen(color, 2, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
        painter.setPen(pen);
        painter.drawPoint(mandelbrotSet[i][0] * 0.9*width(), mandelbrotSet[i][1] * 0.9*height());
    }
}
