#ifndef MYSCENE_HPP
#define MYSCENE_HPP

#include <QGraphicsScene>
#include "edge.hpp"
#include "vertex.hpp"

class MyScene : public QGraphicsScene
{
public:
    MyScene(QGraphicsView* x);

    //Ajout objets
    Vertex* addVertex();
    void addEdge(Edge *e);
};

#endif // MYSCENE_HPP
