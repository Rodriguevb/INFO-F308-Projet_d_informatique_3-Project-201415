#include "myscene.hpp"

MyScene::MyScene(QGraphicsView *x) : QGraphicsScene(x), m_grid()
{
   //TODO
}

Vertex* MyScene::addVertex(){
    QBrush redBrush(Qt::darkBlue);
    QPen blackPen(Qt::darkRed);
    Vertex* x = new Vertex();
    return x;
}

void MyScene::addEdge(Edge *e){

}