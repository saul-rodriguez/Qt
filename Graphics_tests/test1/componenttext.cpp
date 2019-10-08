#include "componenttext.h"

#include <QBrush>
#include <QPainter>
#include <QPen>

ComponentText::ComponentText(QGraphicsItem *parent)
    : QGraphicsObject (parent)
{
    setFlags(ItemIsMovable | ItemIsSelectable);

    m_textSize = 10;
    m_color = Qt::green;
    m_text = "L1";
}

void ComponentText::setText(const QString &text)
{
    m_text = text;
}

void ComponentText::setColor(const QColor &color)
{
    m_color = color;
}

QRectF ComponentText::boundingRect() const
{
    return QRectF(0,0,15,10);
}

void ComponentText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;

    pen.setWidth(1);
    pen.setColor(m_color);

    painter->setPen(pen);
    QFont f = painter->font();
    f.setPointSizeF(m_textSize);
    painter->drawText(0,10,m_text);

    QRectF rec = boundingRect();
    QBrush brush(Qt::transparent);

    painter->fillRect(rec,brush);

}
