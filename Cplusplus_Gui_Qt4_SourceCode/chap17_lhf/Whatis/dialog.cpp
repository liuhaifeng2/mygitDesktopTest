#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->pushButton->setToolTip(tr("This is a pushbutton!"));
    ui->pushButton->setWhatsThis(tr("This ia a pushbutton what this tip!"));

    this->setToolTip(tr("This is a dialog!"));

//    this->setWhatsThis(tr("This is a dialog what this tip!"));
    this->setWhatsThis(tr("<img src=\":/images/icon.png\">"
                          "&nbsp;The meaning of the Source field depends "
                          "on the Type field:"
                          "<ul>"
                          "<li><b>Books</b> have a Publisher"
                          "<li><b>Articles</b>:have a Journal name with "
                          "volume and issue number"
                          "<li><b>These</b> have an Institution name "
                          "and a Department name"
                          "</ul>"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

}
