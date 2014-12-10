#ifndef EDGE_HPP
#define EDGE_HPP

#include <QGraphicsItem>
#include <QPen>
#include <QColor>
#include <QLineF>
#include "vertex.hpp"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Edge : public QGraphicsItem
{
public:
    Edge();
    Edge(Vertex *start, Vertex *end);

    ~Edge();

    Vertex* getStart();
    void setStart(Vertex* a);
    Vertex* getEnd();
    void setEnd(Vertex* a);
    void setColor(const QColor &color);

    void trackNodes();

    //Paint
    QLineF boundingLine() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Override mouse methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


private:
    Vertex* m_start;
    Vertex* m_end;

signals:

public slots:

};

#endif // EDGE_HPP
