#include "renderarea.h"
#include "window.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

Window::Window(int width, int height, int numPCs, int numIterations, int *matPoints)
{
    renderArea = new RenderArea();

    QString numPCsQString;
    QString numIterationsQString;

    numPCsQString.setNum(numPCs);
    numIterationsQString.setNum(numIterations);

    numIterationsLabel = new QLabel ((QString::fromUtf8("Número de iterações: ")).append(numIterationsQString));
    numPCsLabel = new QLabel ((QString::fromUtf8("Número de PCs: ")).append(numPCsQString));

    QVBoxLayout *vertLayout = new QVBoxLayout;
    QHBoxLayout *horiLayout = new QHBoxLayout;

    horiLayout->addWidget(numPCsLabel);
    horiLayout->addWidget(numIterationsLabel);

    vertLayout->addLayout(horiLayout);
    vertLayout->addWidget(renderArea);

    setLayout(vertLayout);

    renderArea->setPaintMatrix(width, height, matPoints);

}
