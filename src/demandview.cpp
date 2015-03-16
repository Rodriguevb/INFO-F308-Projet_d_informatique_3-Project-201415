#include "demandview.hpp"

float DemandView::HIGHDEMAND = 2.6f;
float DemandView::MEDIUMDEMAND = 1.5f;
float DemandView::LOWDEMAND = 0.f;


DemandView::DemandView(MyMainWindow *window) :
    QGraphicsView(window),
    _window(window),
    _scene(this),
    _freeGrid(),
    _demandGrid()
{
    this->setScene(&_scene);
    this->setSceneRect(3,3,440,440);
    initGrids();
    updateScene();
}

DemandView::~DemandView()
{

}

void DemandView::initGrids() {
    for ( int j(0); j < SIZE; ++j ) {
        std::vector< bool > lineFree;
        std::vector< float > lineDemand;
        for ( int i(0); i < SIZE; ++i ) {
            lineFree.push_back(true);
            lineDemand.push_back(0.f);//LOWDEMAND);
        }
        _freeGrid.push_back(lineFree);
        _demandGrid.push_back(lineDemand);
    }
}


void DemandView::updateScene() {
    _scene.clear();
    _scene.drawGrids(_demandGrid,_freeGrid);
}
