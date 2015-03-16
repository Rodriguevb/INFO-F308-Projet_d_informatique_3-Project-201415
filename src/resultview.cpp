#include "resultview.hpp"

ResultView::ResultView(MyMainWindow *window) :
    QGraphicsView(window),
    _window(window),
    _scene(this)
{

}

ResultView::~ResultView()
{

}

