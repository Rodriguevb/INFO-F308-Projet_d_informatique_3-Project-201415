#ifndef DEMANDVIEW_H
#define DEMANDVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "demandscene.hpp"

class MyMainWindow;

class DemandView : public QGraphicsView
{
public:
    static int const SIZE = 7;
    static float HIGHDEMAND;
    static float MEDIUMDEMAND;
    static float LOWDEMAND;
    enum Tool { LOW, MEDIUM, HIGH, BLOCKED, FREE };

private:
    MyMainWindow* _window;
    DemandScene _scene;
    std::vector< std::vector< bool > > _freeGrid;
    std::vector< std::vector < float > > _demandGrid;
    Tool _tool;
public:
    explicit DemandView(MyMainWindow* window = 0);
    ~DemandView();

    void updateScene();
    void mousePressEvent(QMouseEvent* event);
    void setTool(Tool tool);

    void clearDemand();
    std::vector< std::vector< bool > > getFreeGrid();
    std::vector< std::vector < float > > getDemandGrid();

    void setMap(QString filename);

private:
    void initGrids();
    void setInGrid(int x, int y);

};

#include "mymainwindow.hpp"

#endif // DEMANDVIEW_H
