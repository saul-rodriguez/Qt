#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->widget->SetXAxisName(QString("Freq"));
    ui->widget->SetYAxisName(QString("Mag"));
}

Dialog::~Dialog()
{
    delete ui;
}
