#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->widget->SetXAxisName(QString("Freq"));
    ui->widget->SetYAxisName(QString("Mag"));

    //Generate sample data set

    QList<double> x,y;

    for (int i = 1; i < 20; i++) {
        x.append((double)i);
        y.append((double)i*i);
    }

    ui->widget->setDataPoints(x,y);
}

Dialog::~Dialog()
{
    delete ui;
}
