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
    enum DataType{LIGHTED, FREE};
public:
    MyScene(QGraphicsView* x);

    //Ajout objets
    void setMap(QString file);
    Vertex* addVertex();
    void addEdge(Edge *e);

    // Modification des outils:
    void setDataType(DataType dataType);
    void setdataSetter(bool setter);

    // Dessin de la scene.
    void redraw();
    void drawGrid();

    // Event souris
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);

    // Dessin pour le LIGHTED:
    void pressLighted(QMouseEvent* event);
    void moveLighted(QMouseEvent* event);

    // Dessin pour le FREE:
    void pressFree(QMouseEvent* event);
    void moveFree(QMouseEvent* event);

private:
    Grid m_grid;
    QPixmap m_map;
    bool m_mousePressed;
    bool m_dataSetter;
    DataType m_dataType;

};

#endif // MYSCENE_HPP
