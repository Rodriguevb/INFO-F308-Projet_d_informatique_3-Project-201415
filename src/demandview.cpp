#include "demandview.hpp"

float DemandView::HIGHDEMAND = 2.6f;
float DemandView::MEDIUMDEMAND = 1.5f;
float DemandView::LOWDEMAND = 0.f;


DemandView::DemandView(MyMainWindow *window) :
    QGraphicsView(window),
    _window(window),
    _scene(this),
    _freeGrid(),
    _demandGrid(),
    _tool(HIGH)
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
    _freeGrid.clear();
    _demandGrid.clear();
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

void DemandView::mousePressEvent(QMouseEvent* event) {
    setInGrid(event->x(), event->y());
    updateScene();
}

void DemandView::setTool(Tool tool) {
    _tool = tool;
}

void DemandView::setInGrid(int x, int y) {
    x = x / _scene.CELL_SIZE;
    y = y / _scene.CELL_SIZE;

    if ( x >= SIZE ) return;
    if ( y >= SIZE ) return;

    if ( _tool == HIGH ) {
        _demandGrid[x][y] = HIGHDEMAND;
    } else if ( _tool == MEDIUM ) {
        _demandGrid[x][y] = MEDIUMDEMAND;
    } else if ( _tool == LOW ) {
        _demandGrid[x][y] = LOWDEMAND;
    } else if ( _tool == BLOCKED ) {
        _freeGrid[x][y] = false;
    } else if ( _tool == FREE ) {
        _freeGrid[x][y] = true;
    }
}

void DemandView::clearDemand() {
    initGrids();
    updateScene();
}

std::vector< std::vector< bool > > DemandView::getFreeGrid() {
    return _freeGrid;
}

std::vector< std::vector < float > > DemandView::getDemandGrid() {
    return _demandGrid;
}


void DemandView::setMap(QString filename) {
    _scene.setMap(filename);
}
