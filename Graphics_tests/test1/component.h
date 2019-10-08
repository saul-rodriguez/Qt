#ifndef COMPONENT_H
#define COMPONENT_H

#include <QGraphicsItem>
#include "electricdrawitem.h"


// Component is a class for all electrical components (primitives and subcircuits)
class Component : public ElecDrawItem
{
public:
    Component(QGraphicsItem *parent = 0);

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_width;
    int m_height;
};



#endif // COMPONENT_H
