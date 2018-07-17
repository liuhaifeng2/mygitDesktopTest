#include <QApplication>
#include <QDebug>

#include "iconeditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    IconEditor iconEditor;
    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
    qDebug() << "setWindowTitle";
    iconEditor.setIconImage(QImage(":/images/mouse.png"));
    qDebug() << "setIconImage";
    iconEditor.show();

    return app.exec();
}