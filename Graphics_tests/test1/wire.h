#ifndef WIRE_H
#define WIRE_H

#include "electricdrawitem.h"
#include "wiresegment.h"

class Wire : public ElecDrawItem
{
private:
    QColor m_color;

    QVector <QPoint> m_linePoints; //contains all the points in the wire

    QList <WireSegment *> m_wireSegments;

public:
    Wire(QGraphicsItem *parent = 0);

    void setLines(const QVector <QPoint> & points);
    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;



};

#endif // WIRE_H
