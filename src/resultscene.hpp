#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include <QGraphicsScene>

class ResultView;

class ResultScene : public QGraphicsScene
{
private:
    ResultView* _view;
public:
    ResultScene(ResultView* view);
    ~ResultScene();
};

#include "resultview.hpp"

#endif // RESULTSCENE_H
