#include "electricdrawitem.h"


ElecDrawItem::ElecDrawItem(QGraphicsItem *parent)
    : QGraphicsObject (parent)
{
    m_type = electric::WIRE; //default
}

void ElecDrawItem::setType(electric type)
{
    m_type = type;

}

electric ElecDrawItem::getType()
{
    return m_type;
}

void ElecDrawItem::readXML()
{

}

