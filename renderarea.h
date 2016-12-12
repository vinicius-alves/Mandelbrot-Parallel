#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

using namespace std;

class RenderArea: public QWidget
{
    Q_OBJECT

public:

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setPaintMatrix (int numIters, float *pointsMatrix);

protected:

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:

    int numIterations;
    float mandelbrotSet[10000][3];

};

#endif // RENDERAREA_H
