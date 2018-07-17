#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void pressF1Key();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private slots:
    void help();

private:
    QDir directoryOf(const QString &subdir);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
