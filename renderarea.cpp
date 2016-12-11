#include "renderarea.h"
#include <QPoint>
#include <QPainter>
#include <QPen>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(300, 300);
}

QSize RenderArea::sizeHint() const
{
    return QSize(640, 480);
}

void RenderArea::setPaintMatrix(int matWidth, int matHeight, int *pointsMatrix)
{
    width = matWidth;
    height = matHeight;
    //for (int i = 0; i < width; i++)
      //  for (int j = 0; j < height; j++)
        //    mandelbrotSet[i][j] = 0;
    std::copy(pointsMatrix, pointsMatrix + width*height, &mandelbrotSet[0][0]);
//    for (int i = 0; i < width; i++)
//        for (int j = 0; j < height; j++)
//            mandelbrotSet[i][j] = pointsMatrix[i][j];
    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPen pen (QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));

    QPainter painter(this);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, false);

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            if (mandelbrotSet[i][j] > 0)
                painter.drawPoint(i, j);

}
