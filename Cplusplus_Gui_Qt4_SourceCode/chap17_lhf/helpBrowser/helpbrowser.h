#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QWidget>
#include <QDir>
#include <QString>

class QTextBrowser;
class QPushButton;

class HelpBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit HelpBrowser(const QString &path, const QString &page, QWidget *parent = 0);
    ~HelpBrowser();

    static void showPage(const QString &page);

    static QDir directoryOf(const QString &subdir);


private slots:
    void updateWindowTitle();

private:

    QTextBrowser *textBrowser;
    QPushButton *homeButton;
    QPushButton *backButton;
    QPushButton *closeButton;
};

#endif // HELPBROWSER_H
