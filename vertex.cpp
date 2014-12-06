#include "vertex.hpp"
#include "edge.hpp"
Vertex::Vertex(){
    myTextColor = Qt::darkGreen;
    myOutlineColor = Qt::darkRed;
    myBackgroundColor = Qt::white;

    setFlags(ItemIsMovable | ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsMovable);

    update();
}

Vertex::~Vertex(){
    foreach (Edge* e, myEdges)
        delete e;
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
