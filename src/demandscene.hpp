#ifndef DEMANDSCENE_H
#define DEMANDSCENE_H

#include <QGraphicsScene>
#include <QColor>
#include <QPixmap>
#include <iostream>
class DemandView;

class DemandScene : public QGraphicsScene
{
public:
    static const int CELL_SIZE = 64;
private:

    DemandView *_view;
    QColor _lowColor;
    QColor _mediumColor;
    QColor _highColor;
    QPixmap _map;
public:
    DemandScene(DemandView *view);
    ~DemandScene();

    void drawGrids(std::vector< std::vector<float> > demand, std::vector< std::vector<bool> > free);
    void setMap(QString filename);
};


#include "demandview.hpp"

#endif // DEMANDSCENE_H
