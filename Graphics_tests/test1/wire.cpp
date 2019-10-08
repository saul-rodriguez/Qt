#include "wire.h"

#include <QBrush>
#include <QDebug>
#include <QPainter>
#include <QPen>

Wire::Wire(QGraphicsItem *parent)
    : ElecDrawItem (parent)
{
    m_color = Qt::cyan;
    setFlags(ItemIsSelectable);

}

void Wire::setLines(const QVector<QPoint> &points)
{

    m_linePoints.clear();

    QPoint aux;
    foreach(aux, points) {
        m_linePoints.append(aux);
    }

    //Create wiresegments
    int N = m_linePoints.size();

    if (N<2) {
        qDebug()<<"(E) wire.cpp : number of points lower than 2!";
        return;
    }

    WireSegment* segment;
    for (int i = 0; i < (N-1); i++) {
        WireSegment *seg = new WireSegment(this);
        seg->setPoints(m_linePoints[i],m_linePoints[i+1]);
        m_wireSegments.append(seg);
    }

    //Connect wire segments
    if (N<3) { //Wire is composed of only 1 segment
        return;
    }

    int size = m_wireSegments.size();

    if (size == 1) return; // only 1 element detected (unconnected to other wires)

    for (int i = 0; i < (size); i++) {
        if (i ==0) { //First element
            m_wireSegments[0]->setWire2(m_wireSegments[1]);
        } else if (i== (size-1)) { //Last element
                    m_wireSegments[i]->setWire1(m_wireSegments[i-1]);
        } else { //Midle elements
            m_wireSegments[i]->setWire1(m_wireSegments[i-1]);
            m_wireSegments[i]->setWire2(m_wireSegments[i+1]);
        }

    }
}

QRectF Wire::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Wire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*
    QRectF rec = boundingRect();

    QLine line;

    QPen pen;
    pen.setWidth(1);
    pen.setColor(m_color);
    painter->setPen(pen);
    painter->drawLines(m_linePoints);
    */

}
