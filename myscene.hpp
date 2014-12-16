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
    void setMap(QString file);
    Vertex* addVertex();
    void addEdge(Edge *e);

    // Dessin de la scene.
    void redraw();
    void drawGrid();

    // Event souris
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Grid m_grid;
    QPixmap m_map;
    bool m_mousePressed;
    bool m_dataSetter;
};

#endif // MYSCENE_HPP
