#ifndef EDGE_HPP
#define EDGE_HPP

#include <QGraphicsLineItem>
#include <QPen>
#include <QColor>
#include <QLineF>
#include "vertex.hpp"

class Edge : public QGraphicsLineItem
{
public:
    Edge(Vertex *start, Vertex *end);

    ~Edge();

    Vertex* getStart();
    void setStart(Vertex* a);
    Vertex* getEnd();
    void setEnd(Vertex* a);
    void setColor(const QColor &color);

    void trackNodes();


private:
    Vertex* m_start;
    Vertex* m_end;

signals:

public slots:

};

#endif // EDGE_HPP
