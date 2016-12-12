#include "renderarea.h"
#include "window.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

Window::Window(int numIterations, float *matPoints)
{
    renderArea = new RenderArea();

    //QString numPCsQString;
    QString numIterationsQString;

    //numPCsQString.setNum(numPCs);
    numIterationsQString.setNum(numIterations);

    numIterationsLabel = new QLabel ((QString::fromUtf8("Número de iterações: ")).append(numIterationsQString));
    //numPCsLabel = new QLabel (QString::fromUtf8("Número de PCs: "));

    QVBoxLayout *vertLayout = new QVBoxLayout;
    //QHBoxLayout *horiLayout = new QHBoxLayout;

//    horiLayout->addWidget(numPCsLabel);
//    horiLayout->addWidget(numIterationsLabel);

//    vertLayout->addLayout(horiLayout);

    vertLayout->addWidget(numIterationsLabel, 0, Qt::AlignCenter);

    vertLayout->addWidget(renderArea);

    setLayout(vertLayout);

    renderArea->setPaintMatrix(numIterations, matPoints);

}
