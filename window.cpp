#include "renderarea.h"
#include "window.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

Window::Window()
{
    RenderArea *renderArea = new RenderArea();

    numIterationsLabel = new QLabel (QString::fromUtf8("Numero de iteracoes"));
    numPCsLabel = new QLabel (QString::fromUtf8("Numero de PCs"));
    error = new QLabel (QString::fromUtf8("Insira valores positivos validos para PCs e iteraçoes"));

    error->setVisible(false);

    numIterationsLEdit = new QLineEdit;
    numPCsLEdit = new QLineEdit;

    numIterationsLabel->setBuddy(numIterationsLEdit);
    numPCsLabel->setBuddy(numPCsLEdit);

    generate = new QPushButton (QString::fromUtf8("Gerar Conjunto"));

    connect (generate, SIGNAL(clicked(bool)), renderArea, SLOT (generateMandelbrot ()));

    QVBoxLayout *vertLayout = new QVBoxLayout;
    QHBoxLayout *horiLayout1 = new QHBoxLayout;
    QHBoxLayout *horiLayout2 = new QHBoxLayout;

    horiLayout1->addWidget(numPCsLabel);
    horiLayout1->addWidget(numPCsLEdit);

    horiLayout2->addWidget(numIterationsLabel);
    horiLayout2->addWidget(numIterationsLEdit);

    vertLayout->addLayout(horiLayout1);
    vertLayout->addLayout(horiLayout2);
    vertLayout->addWidget(error);
    vertLayout->addWidget(renderArea);
    vertLayout->addWidget(generate);

    setLayout(vertLayout);

}

QString Window::getNumIterations()
{
    return numIterationsLEdit->text();
}

QString Window::getNumPCs()
{
    return numPCsLEdit->text();
}

void Window::setErrorVisible()
{
    error->setVisible(true);
}

void Window::setErrorNotVisible()
{
    error->setVisible(false);
}


