#include "demandscene.hpp"

DemandScene::DemandScene(DemandView* view) :
QGraphicsScene(view),
_view(view),
_lowColor(Qt::black),
_mediumColor(Qt::blue),
_highColor(Qt::yellow),
_map()
{
    _lowColor.setAlpha(75);
    _mediumColor.setAlpha(75);
    _highColor.setAlpha(75);
}

DemandScene::~DemandScene()
{

}

void DemandScene::drawGrids(std::vector< std::vector<float> > demand, std::vector< std::vector<bool> > free) {

    clear();
    this->addPixmap(_map);

    // On dessine les lignes :
    for(int l(0); l < _view->SIZE;++l) {
        int y = CELL_SIZE*l;
        this->addLine(0,y,448,y);
    }

    // On dessine les colonnes
    for(int c(0); c < _view->SIZE;++c) {
        int x = CELL_SIZE*c;
        this->addLine(x,0,x,448);
    }

    for(int l(0); l < _view->SIZE;++l) {

        for(int c(0); c < _view->SIZE;++c) {
            int x = CELL_SIZE*c;
            int y = CELL_SIZE*l;
            QColor color;
            float demandF = demand.at(l).at(c);
            if ( demandF == _view->LOWDEMAND ) {
                color = _lowColor;
            } else if ( demandF == _view->MEDIUMDEMAND) {
                color = _mediumColor;
            } else {
                color = _highColor;
            }
            QBrush brush(color);
            this->addRect(x,y, CELL_SIZE, CELL_SIZE, QPen(), brush);

            if( !free.at(l).at(c) ) {
                int x0 = CELL_SIZE*c;
                int y0 = CELL_SIZE*l;
                int x1 = x0 + CELL_SIZE;
                int y1 = y0 + CELL_SIZE;

                this->addLine(x0,y0,x1,y1);
                this->addLine(x0,y1,x1,y0);
            }
        }
    }
}

void DemandScene::setMap(QString filename) {
    _map.load(filename);
}
