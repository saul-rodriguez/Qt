#include "component.h"

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "port.h"
#include "componenttext.h"

Component::Component(QGraphicsItem *parent)
    : ElecDrawItem(parent)
{
    m_width = 50;
    m_height = 40;
    setFlags(ItemIsMovable | ItemIsSelectable);

    QGraphicsObject *port1 = new port(this);
    ComponentText *labelText = new ComponentText(this);
    //QGraphicsObject *labelText = new ComponentText(this);
    //labelText->setText("M1");

    labelText->setPos(10,20);
    port1->setPos(-2,20);
}

QRectF Component::boundingRect() const
{
    return QRectF(0,0,m_width,m_height);

}

void Component::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::transparent);
    QPen pen;

    pen.setWidth(1);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawRect(rec);

}
