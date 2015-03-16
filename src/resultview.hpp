#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <QGraphicsView>
#include "resultscene.hpp"

class MyMainWindow;

class ResultView : public QGraphicsView
{
private:
    MyMainWindow* _window;
    ResultScene _scene;
public:
    ResultView(MyMainWindow* window);
    ~ResultView();
};

#include "mymainwindow.hpp"

#endif // RESULTVIEW_H
