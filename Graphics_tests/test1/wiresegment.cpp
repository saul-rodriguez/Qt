#include "wiresegment.h"


#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>


WireSegment::WireSegment(QGraphicsItem *parent)
    : ElecDrawItem (parent)
{
    m_point1.setX(0);
    m_point1.setY(0);
    m_point2.setX(0);
    m_point2.setY(0);

    m_penwidth = 1;

    m_color = Qt::cyan;

    m_wire1 = 0;
    m_wire2 = 0;

    m_changex = 1.0;
    m_changey = 1.0;

    m_orientation = orientation::HORIZONTAL;

    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges);

    m_mouseState = mouseState::IDLE;
}

void WireSegment::setPoints(QPoint point1, QPoint point2)
{
    m_point1 = point1;
    m_point2 = point2;

    if (m_point1.rx() == m_point2.rx()) {
        m_orientation = orientation::VERTICAL;
    } else {
        m_orientation = orientation::HORIZONTAL;
    }
}

void WireSegment::setPoint1(QPoint point1)
{
    m_point1 = point1;
}

void WireSegment::setPoint2(QPoint point2)
{
    m_point2 = point2;
}

QPoint WireSegment::getPoint1()
{
    return m_point1;
}

QPoint WireSegment::getPoint2()
{
    return m_point2;
}

void WireSegment::setWire1(WireSegment *wire1)
{
    m_wire1 = wire1;
}

void WireSegment::setWire2(WireSegment *wire2)
{
    m_wire2 = wire2;
}

QRectF WireSegment::boundingRect() const
{
    double extra = 4*(m_penwidth/2.0);

    QRectF aux(m_point1,m_point2);
    aux = aux.normalized();
    aux = aux.adjusted(-extra,-extra,extra,extra);

    return aux;
}

void WireSegment::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen;
    pen.setWidth(1);
    pen.setColor(m_color);
    painter->setPen(pen);
    painter->drawLine(m_point1,m_point2);
}

void WireSegment::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"mouse press";

    QPointF aux, average;
    aux = event->pos();
    average.setX((m_point1.rx()+m_point2.rx())/2.0);
    average.setY((m_point1.ry()+m_point2.ry())/2.0);

    //Calculate distance to center of segment
    QPointF dis_c = average - aux;
    double dis_cf = qSqrt(qPow(dis_c.rx(),2)+qPow(dis_c.ry(),2));

    //Calculate distances to borders
    QPointF dis_1 = m_point1 - aux;
    double dis_1f = qSqrt(qPow(dis_1.rx(),2)+qPow(dis_1.ry(),2));
    QPointF dis_2 = m_point2 - aux;
    double dis_2f = qSqrt(qPow(dis_2.rx(),2)+qPow(dis_2.ry(),2));


    //qDebug()<<"pos: "<<pos() <<" scenePos: " << scenePos()<< " aux: "<<aux<< " average: "<<average << " Distance to center: "<<dis_c;
    qDebug()<<"disc: " << dis_cf <<" dis1: " << dis_1f << " dis2: " << dis_2f;

    if (dis_cf < dis_1f && dis_cf < dis_2f) { // Move the segment
        m_mouseState = mouseState::CENTER;
    } else if (dis_1f < dis_2f) { // Move point1
        if (!m_wire1) {
            m_mouseState = mouseState::POINT1;
        } else {
            m_mouseState = mouseState::CENTER;
        }

    } else { //Move point2
        if (!m_wire2) {
            m_mouseState = mouseState::POINT2;
        } else {
            m_mouseState = mouseState::CENTER;
        }
    }

    QGraphicsObject::mousePressEvent(event);
    update();
}

void WireSegment::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF aux;
    aux = event->pos();

    if (m_mouseState == mouseState::POINT1) {
        if (m_orientation == orientation::VERTICAL) {
            m_point1.setY(aux.ry());
        } else {
            m_point1.setX(aux.rx());
        }
        update();

    } else if (m_mouseState == mouseState::POINT2) {
        if (m_orientation == orientation::VERTICAL) {
            m_point2.setY(aux.ry());
        } else {
            m_point2.setX(aux.rx());
        }
        update();

    } else {

        qDebug()<<"mouse move to: X =" << aux.rx() << " Y =" << aux.ry();
        qDebug()<<"item x =" <<pos().rx() << " y =" <<pos().ry();

        QGraphicsObject::mouseMoveEvent(event);
    }
}

void WireSegment::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"mouse release";
    m_mouseState = mouseState::IDLE;

    QGraphicsObject::mouseReleaseEvent(event);
    update();
}

QVariant WireSegment::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    qDebug() << "Item change";

    if (change == ItemPositionChange) {
        QPointF ret;
        if (m_orientation == orientation::VERTICAL) {

            ret = QPointF(value.toPointF().x(), pos().y()); //The new adjusted position is the final position!

            qDebug()<<"V: ret x = "<< ret.rx() << " ret y = " << ret.ry();

            if (m_changex != ret.rx()) {
                double diff = ret.rx()  - m_changex;
                m_changex = ret.rx();

                if (m_wire1) {
                    m_wire1->prepareGeometryChange();
                    QPoint aux;
                    aux.setX(m_wire1->getPoint2().rx()+diff);
                    aux.setY(m_wire1->getPoint2().ry());
                    m_wire1->setPoint2(aux);
                    m_wire1->update();
                }

                if(m_wire2) {
                    m_wire2->prepareGeometryChange();
                    QPoint aux;
                    aux.setX(m_wire2->getPoint1().rx()+diff);
                    aux.setY(m_wire2->getPoint1().ry());
                    m_wire2->setPoint1(aux);
                    m_wire2->update();
                }
           }

        } else {
            ret = QPointF(pos().x(), value.toPointF().y()); //The new adjusted position is the final position!

            qDebug()<<"H: ret x = "<< ret.rx() << "ret y = " << ret.ry();

            if (m_changey != ret.ry()) {
                    double diff = ret.ry() - m_changey;
                    m_changey = ret.ry();

                    if (m_wire1) {
                        qDebug()<<"moving wire1";
                        m_wire1->prepareGeometryChange();
                        QPoint aux;
                        aux.setX(m_wire1->getPoint2().rx());
                        aux.setY(m_wire1->getPoint2().ry() + diff);
                        m_wire1->setPoint2(aux);
                        m_wire1->update();
                    }

                    if (m_wire2) {
                        m_wire2->prepareGeometryChange();
                        QPoint aux;
                        aux.setX(m_wire2->getPoint1().rx());
                        aux.setY(m_wire2->getPoint1().ry() + diff);
                        m_wire2->setPoint1(aux);
                        m_wire2->update();
                    }
            }
        }

        return ret;
    }

    return QGraphicsObject::itemChange(change,value);
}
