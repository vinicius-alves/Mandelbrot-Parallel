#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea: public QWidget
{
    Q_OBJECT

public:

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void generateMandelbrot(QString numPCsQString, QString numIterationsQString);

protected:

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:

    int numPCs, numIterations, total;
    bool teste = false;

};

#endif // RENDERAREA_H
