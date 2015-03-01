#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsView>
#include "myscene.hpp"
#include <QBrush>
#include <QPen>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include "vertex.hpp"
#include "edge.hpp"
#include <iostream>
#include <QDebug>
#include <QPixmap>

class HomePage : public QGraphicsView
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = 0);

    void setMap(QString file);
    void addEdge();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    // Modification des outils
    void setDataType(MyScene::DataType dataType);
    void setDataSetter(bool setter);
    void setTool(MyScene::ToolType tool);

    void drawAmplResult(AmplResult result);

private:
    MyScene *scene;
    QPoint point;
    QGraphicsItem *x;


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
