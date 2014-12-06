#include "edge.hpp"
#include "vertex.hpp"

Edge::Edge(Vertex *start, Vertex *end)
{
    setStart(start);
    setEnd(end);

    this->getStart()->addEdge(this);
    this->getEnd()->addEdge(this);

    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::darkBlue);
    this->trackNodes();
}

Edge::~Edge(){
    this->getStart()->removeEdge(this);
    this->getEnd()->removeEdge(this);
}

void Edge::setColor(const QColor &color){
    setPen(QPen(color, 1.0));
}

void Edge::trackNodes(){
    setLine(QLineF(getStart()->pos(), getEnd()->pos()));
}

Vertex* Edge::getStart(){
    return m_start;
}

void Edge::setStart(Vertex* a){
    m_start=a;
}

Vertex* Edge::getEnd(){
    return m_end;
}

void Edge::setEnd(Vertex* a){
    m_end=a;
}
