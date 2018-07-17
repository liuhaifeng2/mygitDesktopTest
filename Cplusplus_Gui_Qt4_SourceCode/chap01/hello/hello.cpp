#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("你好, 欢迎来到Qt世界!", Q_NULLPTR);
    label->resize(400, 300);
    label->setWindowTitle("Hello 小程序");
    label->show();

    return app.exec();
}
