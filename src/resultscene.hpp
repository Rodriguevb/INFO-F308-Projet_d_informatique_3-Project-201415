#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPixmap>
#include "amplresult.hpp"

class ResultView;

class ResultScene : public QGraphicsScene
{
public:
    static const int CELL_SIZE = 64;
private:
    ResultView* _view;
    QPixmap _map;
public:
    ResultScene(ResultView* view);
    ~ResultScene();

    void drawResult(AmplResult result);
    void setMap(QString filename);
private:
    double roundDouble(double toround);
};

#include "resultview.hpp"

#endif // RESULTSCENE_H
