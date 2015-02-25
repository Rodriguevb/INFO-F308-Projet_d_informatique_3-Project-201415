#include "homepage.hpp"

HomePage::HomePage(QWidget *parent) :
    QGraphicsView(parent)
{

    scene = new MyScene(this);
    this->setScene(scene);
}

void HomePage::setMap(QString file){
    qDebug() <<"HomePage : setMap";
    this->setRenderHints(QPainter::Antialiasing);
    scene->setMap(file);
    scene->redraw();
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

void HomePage::mouseReleaseEvent(QMouseEvent *event){

    scene->mouseReleaseEvent(event);

}

void HomePage::mouseMoveEvent(QMouseEvent *event){

    scene->mouseMoveEvent(event);

}

void HomePage::setDataType(MyScene::DataType dataType) {
    scene->setDataType(dataType);
}

void HomePage::setDataSetter(bool setter) {
    scene->setdataSetter(setter);
}

void HomePage::setTool(MyScene::ToolType tool) {
    scene->setTool(tool);
}

void HomePage::drawAmplResult(AmplResult result) {
    scene->drawAmplResult(result);
}


