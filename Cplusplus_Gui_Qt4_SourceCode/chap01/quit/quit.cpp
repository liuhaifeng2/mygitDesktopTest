#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *button = new QPushButton("Quit", Q_NULLPTR);
    QObject::connect(button, SIGNAL(clicked()),
                     &app, SLOT(quit()));
    button->setWindowTitle("退出按钮程序");
    button->resize(400, 300);
    button->show();
    return app.exec();
}
