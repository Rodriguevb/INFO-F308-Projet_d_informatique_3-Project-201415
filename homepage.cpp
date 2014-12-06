#include "homepage.hpp"

HomePage::HomePage(QWidget *parent) :
    QGraphicsView(parent)
{

    scene = new QGraphicsScene(this);
    this->setScene(scene);
    //line = new QGraphicsLineItem(10,10,125,345);

    QBrush redBrush(Qt::black);
    QPen blackPen(Qt::black);
    blackPen.setWidth(10);


    line = scene->addLine(100,10,125,345, blackPen);
    line->setFlag(QGraphicsItem::ItemIsFocusable);
    line->setFlag(QGraphicsItem::ItemIsSelectable);
    line->setFlag(QGraphicsItem::ItemIsMovable);

}

void HomePage::addVertex(Vertex *v){
    QBrush redBrush(Qt::darkBlue);
    QPen blackPen(Qt::darkRed);
    x = scene->addEllipse(100,100,15,15,blackPen, redBrush);
    x->setFlag(QGraphicsItem::ItemIsFocusable);
    x->setFlag(QGraphicsItem::ItemIsSelectable);
    x->setFlag(QGraphicsItem::ItemIsMovable);
    //TODO : relier l'objet x au Vertex v :-)

}

/*void HomePage::paintEvent ( QPaintEvent * event ){
    QPainter painter;
    QPen pen(Qt::darkBlue);
    pen.setWidth(10);
    std::cout<<"paint event"<<std::endl;

    painter.setPen(pen);

    painter.setBrush(Qt::darkRed);
    painter.drawEllipse(100,100, 150,150);

    update();

}*/
