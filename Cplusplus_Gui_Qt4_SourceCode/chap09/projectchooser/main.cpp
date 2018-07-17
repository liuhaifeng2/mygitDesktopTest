//#include <QtGui>
#include <QtWidgets>

#include "projectdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ProjectDialog dialog;
    dialog.resize(600, 480);
    dialog.show();
    return app.exec();
}
