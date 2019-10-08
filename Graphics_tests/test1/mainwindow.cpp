#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "component.h"
#include "wire.h";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::black);
    ui->graphicsView->setScene(scene);

    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //Add a few components
    Component *component;

    component = new Component;
    component->setPos(120,120);
    scene->addItem(component);

    component = new Component;
    component->setPos(120,0);
    scene->addItem(component);

    //Create wires
    QVector <QPoint> wire1;
    wire1.append(QPoint(0,0));
    wire1.append(QPoint(10,0));   
    wire1.append(QPoint(10,50));
    wire1.append(QPoint(0,50));
    wire1.append(QPoint(0,30));

    Wire *wire;

    wire = new Wire;
    wire->setLines(wire1);
    scene->addItem(wire);

    //Create a segment

    WireSegment *segment;
    segment = new WireSegment;
    segment->setPoints(QPoint(30,30),QPoint(30,40));
    scene->addItem(segment);



}

MainWindow::~MainWindow()
{
    delete ui;
}
