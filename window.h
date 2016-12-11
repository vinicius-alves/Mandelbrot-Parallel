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

//class RenderArea;

class Window: public QWidget
{
    Q_OBJECT

public:
    Window();
    static QString getNumIterations();
    static QString getNumPCs();
    static void setErrorVisible();
    static void setErrorNotVisible();

private:
    static QLineEdit *numIterationsLEdit;
    static QLineEdit *numPCsLEdit;
    QLabel *numIterationsLabel;
    QLabel *numPCsLabel;
    static QLabel *error;
    QPushButton *generate;

};

#endif // WINDOW_H
