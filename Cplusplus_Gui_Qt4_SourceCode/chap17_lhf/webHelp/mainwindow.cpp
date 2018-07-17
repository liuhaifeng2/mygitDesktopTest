#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(pressF1Key()), this, SLOT(help()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_F1)
    {
        emit pressF1Key();
    }
}

void MainWindow::help()
{
    qDebug() << "invoke help()";

//    QUrl url("www.baidu.com");
//    QDesktopServices::openUrl(url);

    QUrl url(directoryOf("doc").absoluteFilePath("forms.html"));
//    url.setScheme("file");
//    url.setFragment("editing");
    QDesktopServices::openUrl(url);
}

QDir MainWindow::directoryOf(const QString &subdir)
{
    QDir dir(QApplication::applicationDirPath());

    if (dir.dirName().toLower() == "debug"
            || dir.dirName().toLower() == "release")
    {
        dir.cdUp();
    }

    dir.cd(subdir);
    return dir;
}

















