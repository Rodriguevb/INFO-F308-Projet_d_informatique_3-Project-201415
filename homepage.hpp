#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include "vertex.hpp"
#include "edge.hpp"
#include <iostream>

class HomePage : public QGraphicsView
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = 0);

    void addVertex(Vertex *v);
//    void paintEvent ( QPaintEvent * event );

private:
    QGraphicsScene *scene;
    QPoint point;
    QGraphicsLineItem *line;
    QGraphicsItem *x;
    //QGraphicsItem *point;


signals:

public slots:


private slots:
   /*void addVertex();
   void addEdge();
   void del();
   void cut();
   void copy();
   void paste();
   void bringToFront();
   void sendToBack();
   void properties();
   void updateActions();*/
};

#endif // HOMEPAGE_HPP
