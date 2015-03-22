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

void ResultView::drawResult(AmplResult result, bool showlight) {
    _scene.drawResult(result, showlight);
}

void ResultView::setMap(QString filename) {
    _scene.setMap(filename);
}
