#ifndef DEMANDSCENE_H
#define DEMANDSCENE_H

#include <QGraphicsScene>
#include <QColor>
#include <iostream>
class DemandView;

class DemandScene : public QGraphicsScene
{
private:
    static const int CELL_SIZE = 64;

    DemandView *_view;
    QColor _lowColor;
    QColor _mediumColor;
    QColor _highColor;
public:
    DemandScene(DemandView *view);
    ~DemandScene();

    void drawGrids(std::vector< std::vector<float> > demand, std::vector< std::vector<bool> > free);
};


#include "demandview.hpp"

#endif // DEMANDSCENE_H