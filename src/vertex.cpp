#include "vertex.hpp"
#include "edge.hpp"
Vertex::Vertex(){
    myTextColor = Qt::darkGreen;
    myOutlineColor = Qt::darkRed;
    myBackgroundColor = Qt::white;

    setFlags(ItemIsMovable | ItemIsSelectable);
    //this->setFlag(QGraphicsItem::ItemIsMovable);

    update();
}

Vertex::~Vertex(){
    foreach (Edge* e, myEdges)
        delete e;
}


void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "You clicked on Vertex " << this->getName();
    //this->setFlag(QGraphicsItem::ItemIsMovable,false);
    //this->setFlag(QGraphicsItem::ItemIsSelectable,false);
    update();
    QGraphicsItem::mousePressEvent(event);;

}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::red, 3);
    painter->setPen(pen);
    painter->drawEllipse(rect);
}

QRectF Vertex::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void Vertex::setText(const QString &name){
    prepareGeometryChange();
    m_name = name;
    update();
}

QString Vertex::getName() const{
    return m_name;
}

void Vertex::setTextColor(const QColor &color){
    myTextColor = color;
    update();
}

QColor Vertex::textColor() const{

}

void Vertex::setOutlineColor(const QColor &color){

}

QColor Vertex::outlineColor() const{

}

void Vertex::setBackgroundColor(const QColor &color){

}

QColor Vertex::backgroundColor() const{

}

void Vertex::addEdge(Edge* e){
    myEdges.insert(e);
}

void Vertex::removeEdge(Edge* e){
    myEdges.remove(e);
}
