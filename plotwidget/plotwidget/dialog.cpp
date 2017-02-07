#include "dialog.h"
#include "ui_dialog.h"
#include "math.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->widget->SetXAxisName(QString("Freq"));
    ui->widget->SetYAxisName(QString("Mag"));

    //Generate sample data set

    QList<double> x,y;
    QList<double> y1,y2,y3;

    for (int i = 1; i < 20; i++) {
        x.append((double)i);
        y.append((double)i*i);

        y1.append((double)i*2);
        y2.append((double)i*10);
        y3.append((double)sqrt((double)i));

    }

    ui->widget->setDataPoints(x,y);
    ui->widget->appendCurve(x,y);
    ui->widget->appendCurve(x,y1);
    ui->widget->appendCurve(x,y2);
    ui->widget->appendCurve(x,y3);
}

Dialog::~Dialog()
{
    delete ui;
}
