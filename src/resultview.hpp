#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <QGraphicsView>
#include "resultscene.hpp"
#include "amplresult.hpp"

class MyMainWindow;

class ResultView : public QGraphicsView
{
public:
    static int const SIZE = 7;
private:
    MyMainWindow* _window;
    ResultScene _scene;
public:
    ResultView(MyMainWindow* window);
    ~ResultView();

    void drawResult(AmplResult result);
    void setMap(QString filename);
};

#include "mymainwindow.hpp"

#endif // RESULTVIEW_H
