#ifndef DEMANDVIEW_H
#define DEMANDVIEW_H

#include <QGraphicsView>
#include "demandscene.hpp"

class MyMainWindow;

class DemandView : public QGraphicsView
{
public:
    static int const SIZE = 7;
    static float HIGHDEMAND;
    static float MEDIUMDEMAND;
    static float LOWDEMAND;
private:
    MyMainWindow* _window;
    DemandScene _scene;
    std::vector< std::vector< bool > > _freeGrid;
    std::vector< std::vector < float > > _demandGrid;
public:
    explicit DemandView(MyMainWindow* window = 0);
    ~DemandView();

    void updateScene();

private:
    void initGrids();
};

#include "mymainwindow.hpp"

#endif // DEMANDVIEW_H
