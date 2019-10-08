#ifndef WIRESEGMENT_H
#define WIRESEGMENT_H

#include "electricdrawitem.h"

enum orientation {
    HORIZONTAL,
    VERTICAL
};
typedef enum orientation orientation;

enum mouseState {
    IDLE,
    CENTER,
    POINT1,
    POINT2
};
typedef enum mouseState mouseState;

class WireSegment : public ElecDrawItem
{
private:
    QPoint m_point1, m_point2;
    double m_penwidth;
    QColor m_color;
    orientation m_orientation;
    mouseState m_mouseState;

    WireSegment* m_wire1, *m_wire2; //Wires located on the sides that may need to move with this wire
                                    // m_wire1.point2 connects to this.point1
                                    // this.point2 connects to m_wire2.point1
    double m_changex;
    double m_changey;

    //QList <WireSegment*> m_otherWires; //other wires that end somewhere in the middle


public:
    WireSegment(QGraphicsItem *parent = 0);

    void setPoints(QPoint point1, QPoint point2);
    void setPoint1(QPoint point1);
    void setPoint2(QPoint point2);
    QPoint getPoint1();
    QPoint getPoint2();

    void setWire1(WireSegment *wire1);
    void setWire2(WireSegment *wire2);


    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsItem interface
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
};

#endif // WIRESEGMENT_H
