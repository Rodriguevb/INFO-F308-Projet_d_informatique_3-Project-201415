#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "amplresult.hpp"

class ResultView;

class ResultScene : public QGraphicsScene
{
public:
    static const int CELL_SIZE = 64;
private:
    ResultView* _view;
public:
    ResultScene(ResultView* view);
    ~ResultScene();

    void drawResult(AmplResult result);
private:
    double roundDouble(double toround);
};

#include "resultview.hpp"

#endif // RESULTSCENE_H
