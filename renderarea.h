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

public slots:

    void generateMandelbrot();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:

    bool teste = false;
    QString *blabla;
    QString *bleble;
    void setMaxSize();

};

#endif // RENDERAREA_H
