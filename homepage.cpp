#include "homepage.hpp"

HomePage::HomePage(QWidget *parent) :
    QGraphicsView(parent)
{

    scene = new MyScene(this);
    this->setScene(scene);
}

void HomePage::addVertex(){
    qDebug() <<"HomePage : addVertex";
    Vertex* y = new Vertex();
    y->setText("BXL");
    scene->addItem(y);
}

void HomePage::addEdge(){
    qDebug() <<"HomePage : addEdge";
    Edge* y = new Edge();
    scene->addItem(y);
}

void HomePage::mousePressEvent(QMouseEvent *event){

    QGraphicsView::mousePressEvent(event);

}

