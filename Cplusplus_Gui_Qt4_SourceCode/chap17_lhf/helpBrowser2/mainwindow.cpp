#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpbrowser.h"
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

//    HelpBrowser::showPage("index.html");
    HelpBrowser::showPage("forms.html");
}

















