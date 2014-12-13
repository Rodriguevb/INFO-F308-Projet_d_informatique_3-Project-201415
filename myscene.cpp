#include "myscene.hpp"

MyScene::MyScene(QGraphicsView *x) :
    QGraphicsScene(0,0,800,600,x),
    m_grid(32,this->width(),this->height()),
    m_map(),
    m_mousePressed(false),
    m_dataSetter(0)
{
   //TODO
    drawGrid();
}

void MyScene::setMap(QString file) {
    m_map.load(file);
    m_map = m_map.scaled(m_grid.getWidth(),m_grid.getHeight(),Qt::KeepAspectRatio);
}

Vertex* MyScene::addVertex(){
    QBrush redBrush(Qt::darkBlue);
    QPen blackPen(Qt::darkRed);
    Vertex* x = new Vertex();
    return x;
}

void MyScene::addEdge(Edge *e){

}

void MyScene::redraw() {
    clear();
    this->addPixmap(m_map);
    drawGrid();
}

void MyScene::drawGrid() {
    // Affichage de la grille
    for(int l(0); l < m_grid.getNbLine();++l) {
        int y = m_grid.getCaseSize()*l;
        this->addLine(0,y,m_grid.getWidth(),y);
    }

    for(int c(0); c < m_grid.getNbColumn();++c) {
        int x = m_grid.getCaseSize()*c;
        this->addLine(x,0,x,m_grid.getHeight());
    }

    // On dessine les cases dont la valeur est de 1.
    for(int l(0); l < m_grid.getNbLine();++l) {
        for(int c(0); c < m_grid.getNbColumn();++c) {
            int data = m_grid.get(l,c);
            if ( data == 1 ) {
                int x = m_grid.getCaseSize()*c;
                int y = m_grid.getCaseSize()*l;

                QColor color("red");
                color.setAlphaF(0.5);
                QBrush brush(color);
                addRect(x,y, m_grid.getCaseSize(), m_grid.getCaseSize(), QPen(), brush);

            }
        }
    }

}

void MyScene::mousePressEvent(QMouseEvent* event) {
    if ( event->button() == Qt::LeftButton ) {
        m_mousePressed = true;
        int col = m_grid.xToColumn(event->pos().x());
        int line = m_grid.yToLine(event->pos().y());
        int ex_data = m_grid.get(line,col);
        m_dataSetter = (ex_data == 0) ? 1 : 0;
        m_grid.set(line,col,m_dataSetter);

        redraw();
    }
}

void MyScene::mouseReleaseEvent(QMouseEvent *event) {
    m_mousePressed = false;
}

void MyScene::mouseMoveEvent(QMouseEvent *event) {
    int x = event->pos().x();
    int y = event->pos().y();
    int col = m_grid.xToColumn(x);
    int line = m_grid.yToLine(y);
    if ((m_grid.caseExist(line,col)) && (m_grid.get(line,col) != m_dataSetter)) {
        m_grid.set(line,col,m_dataSetter);
        redraw();
    }

}
