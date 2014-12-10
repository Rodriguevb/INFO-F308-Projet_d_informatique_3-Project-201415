#include "edge.hpp"
#include "vertex.hpp"

Edge::Edge(){
    setFlag(QGraphicsItem::ItemClipsChildrenToShape);
}

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
    //setPen(QPen(color, 1.0));
}

void Edge::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "You clicked on Edge ";
    this->setFlag(QGraphicsItem::ItemIsMovable);
    //this->setFlag(QGraphicsItem::ItemIsSelectable,false);
    update();
    QGraphicsItem::mousePressEvent(event);

}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLineF line = boundingLine();
    QPen pen(Qt::darkBlue, 8);
    painter->setPen(pen);
    painter->drawLine(line);
}

QLineF Edge::boundingLine() const
{
    // outer most edges
    return QLineF(0,0,100,25);
    //return QLineF(getStart()->pos(),getEnd()->pos());
}


QRectF Edge::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void Edge::trackNodes(){
    //setLine(QLineF(getStart()->pos(), getEnd()->pos()));
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
