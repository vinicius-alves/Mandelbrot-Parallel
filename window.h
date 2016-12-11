#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class QLineEdit;
class QLabel;
class QPushButton;

QT_END_NAMESPACE

class RenderArea;

class Window: public QWidget
{
    Q_OBJECT

public:
    Window(int width, int height, int numPCs, int numIterations, int *matPoints);

private:

    RenderArea *renderArea;
    QLabel *numIterationsLabel;
    QLabel *numPCsLabel;

};

#endif // WINDOW_H
