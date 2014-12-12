#include "myscene.hpp"

MyScene::MyScene(QGraphicsView *x) :
    QGraphicsScene(0,0,800,600,x),
    m_grid(32,this->width(),this->height())
{
   //TODO
    drawGrid();
}

Vertex* MyScene::addVertex(){
    QBrush redBrush(Qt::darkBlue);
    QPen blackPen(Qt::darkRed);
    Vertex* x = new Vertex();
    return x;
}

void MyScene::addEdge(Edge *e){

}

void MyScene::drawGrid() {
    for(int l(0); l < m_grid.getNbLine();++l) {
        int y = m_grid.getCaseSize()*l;
        this->addLine(0,y,m_grid.getWidth(),y);
    }

    for(int c(0); c < m_grid.getNbColumn();++c) {
        int x = m_grid.getCaseSize()*c;
        this->addLine(x,0,x,m_grid.getHeight());
    }

}
