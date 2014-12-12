#include "homepage.hpp"

HomePage::HomePage(QWidget *parent) :
    QGraphicsView(parent)
{

    scene = new MyScene(this);
    this->setScene(scene);
}

void HomePage::setMap(QString file){
    qDebug() <<"HomePage : setMap";
    QPixmap fondPlan;
    fondPlan.load(file);
    scene->addPixmap(fondPlan);
    //scene->setSceneRect(0,0, fondPlan.width(), fondPlan.height());
    //this->resize(fondPlan.width()+10, fondPlan.height()+10);
    this->setRenderHints(QPainter::Antialiasing);
    scene->drawGrid();
    update();

}

void HomePage::addEdge(){
    qDebug() <<"HomePage : addEdge";
    Edge* y = new Edge();
    scene->addItem(y);
}

void HomePage::mousePressEvent(QMouseEvent *event){

    scene->mousePressEvent(event);

}

