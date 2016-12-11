#include "renderarea.h"
#include <QPoint>
#include <QPainter>
#include <QPen>
#include "window.h"
#include <string.h>

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

void RenderArea::generateMandelbrot()
{
    //int numIterations = strtol ((String)(Window::getNumIterations()));
    //int numPCs = strtol (static_cast <String>(Window::getNumPCs()));

    //if (numIterations != 0 && numPCs != 0)
    //{
    //    teste = true;
    //}
    //teste = false;
    update();

}

void RenderArea::paintEvent(QPaintEvent * /* event */){

    QPen pen (QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));

    QPainter painter(this);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.translate((width()/2), (height()/2));

    if (teste)
    {
        Window::setErrorNotVisible();
        static const QPoint points[4] = {
            QPoint(200, 200),
            QPoint(-10, -50),
            QPoint(80, 30),
            QPoint(90, 70)
        };
        painter.drawPoints(points, 4);

        painter.drawText(0, 0, *blabla);
        painter.drawText(50, 50, *bleble);

    }
    else
    {
        Window::setErrorVisible();
    }
}
