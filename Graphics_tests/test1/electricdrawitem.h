#ifndef ELECTRICDRAWITEM_H
#define ELECTRICDRAWITEM_H

#include <QGraphicsItem>

enum electric {
    WIRE,
    COMPONENT,
    OTHER
};

typedef enum electric electric;

//ElecDrawItem is an abstract class for all items drawn on a schematic view
class ElecDrawItem : public QGraphicsObject
{
public:
    ElecDrawItem(QGraphicsItem *parent = 0);

    void setType(electric type);
    electric getType();

    virtual void readXML();

private:
    electric m_type;

};

#endif // ELECTRICDRAWITEM_H
