#include "resultview.hpp"

ResultView::ResultView(MyMainWindow *window) :
    QGraphicsView(window),
    _window(window),
    _scene(this)
{
    setScene(&_scene);
    setSceneRect(3,3,440,440);
}

ResultView::~ResultView()
{

}

void ResultView::drawResult(AmplResult result) {
    _scene.drawResult(result);
}
