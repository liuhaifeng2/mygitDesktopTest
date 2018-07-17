#include <QApplication>
#include <QTranslator>
#include <QDebug>

#include "diagramwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator *pTrans = new QTranslator();
    bool b = pTrans->load("diagram.qm");
    qDebug() << "load is " << b;
    b = app.installTranslator(pTrans);
    qDebug() << "installTranslator is " << b;
    DiagramWindow view;
    view.show();
    return app.exec();
}
