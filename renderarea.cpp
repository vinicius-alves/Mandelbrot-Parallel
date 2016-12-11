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

void RenderArea::generateMandelbrot(QString numPCsQString, QString numIterationsQString)
{

    bool ok1, ok2;

    numPCs = numPCsQString.toInt(&ok1);
    numIterations = numIterationsQString.toInt(&ok2);

    if (ok1 && ok2 && numPCs != 0 && numIterations != 0)
    {
        total = numPCs + numIterations;
        teste = true;
    }
    else
        teste = false;

    update();

}

void RenderArea::paintEvent(QPaintEvent * /* event */){

    QPen pen (QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));

    QPainter painter(this);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.translate((width()/2), (height()/2));

    if (!teste)
    {
        static const QPoint points[4] = {
            QPoint(200, 200),
            QPoint(-10, -50),
            QPoint(80, 30),
            QPoint(90, 70)
        };
        painter.drawPoints(points, 4);

    }
   else
        painter.drawPoint(total, total);

}
