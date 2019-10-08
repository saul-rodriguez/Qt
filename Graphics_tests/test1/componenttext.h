#ifndef COMPONENTTEXT_H
#define COMPONENTTEXT_H

#include <QGraphicsItem>

// ComponentText is a class for all texts belonging to a component (label, parameters, etc)
class ComponentText : public QGraphicsObject
{
public:
    ComponentText(QGraphicsItem *parent = 0);

    void setText(const QString& text);
    void setColor(const QColor& color);
    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_textSize;
    QColor m_color;
    QString m_text;

};

#endif // COMPONENTTEXT_H
