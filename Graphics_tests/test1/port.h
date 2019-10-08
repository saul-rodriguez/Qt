#ifndef PORT_H
#define PORT_H

#include <QGraphicsItem>

class port : public QGraphicsObject
{
public:
    port(QGraphicsItem *parent = 0);



    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int portSize;
};

#endif // PORT_H
