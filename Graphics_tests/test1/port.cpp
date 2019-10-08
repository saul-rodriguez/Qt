#include "port.h"

#include <QBrush>
#include <QPainter>
#include <QPen>

port::port(QGraphicsItem *parent)
    : QGraphicsObject (parent)
{
    setFlags(ItemIsMovable | ItemIsSelectable);

    portSize = 5;

}

QRectF port::boundingRect() const
{
    return QRectF(0,0,portSize,portSize);
}

void port::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::red);

    painter->fillRect(rec,brush);
}
