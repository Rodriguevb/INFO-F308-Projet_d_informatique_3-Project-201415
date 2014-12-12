#ifndef MYSCENE_HPP
#define MYSCENE_HPP

#include <QGraphicsScene>
#include "edge.hpp"
#include "vertex.hpp"
#include "grid.hpp"
#include <iostream>

class MyScene : public QGraphicsScene
{
public:
    MyScene(QGraphicsView* x);

    //Ajout objets
    Vertex* addVertex();
    void addEdge(Edge *e);

    // Dessin de la scene.
    void drawGrid();

private:
    Grid m_grid;
};

#endif // MYSCENE_HPP
