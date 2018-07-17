#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello!", Q_NULLPTR);
    label->resize(400, 300);
    label->setWindowTitle("Hello");
    label->show();
    
    return app.exec();
}