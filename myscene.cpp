#include "myscene.hpp"

MyScene::MyScene(QGraphicsView *x) :
    QGraphicsScene(0,0,800,600,x),
    m_grid(32,this->width(),this->height()),
    m_map(),
    m_mousePressed(false),
    m_dataSetter(true),
    m_dataType(LIGHTED),
    m_tool(PENCIL)
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

void MyScene::setDataType(DataType dataType) {
    m_dataType = dataType;
}

void MyScene::setdataSetter(bool setter) {
    m_dataSetter = setter;
}

void MyScene::setTool(ToolType tool) {
    m_tool = tool;
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

    // On dessine les cases.
    for(int l(0); l < m_grid.getNbLine();++l) {
        for(int c(0); c < m_grid.getNbColumn();++c) {
            if ( m_grid.getLighted(l,c) ) {
                int x = m_grid.getCaseSize()*c;
                int y = m_grid.getCaseSize()*l;

                QColor color("red");
                color.setAlphaF(0.5);
                QBrush brush(color);
                addRect(x,y, m_grid.getCaseSize(), m_grid.getCaseSize(), QPen(), brush);

            }

            if( !m_grid.getFree(l,c) ) {
                int x0 = m_grid.getCaseSize()*c;
                int y0 = m_grid.getCaseSize()*l;
                int x1 = x0 + m_grid.getCaseSize();
                int y1 = y0 + m_grid.getCaseSize();

                this->addLine(x0,y0,x1,y1);
                this->addLine(x0,y1,x1,y0);
            }
        }
    }

}

void MyScene::mousePressEvent(QMouseEvent* event) {
    if ( event->button() == Qt::LeftButton ) {
        m_mousePressed = true;
        if ( m_dataType == LIGHTED) {
            pressLighted(event);
        }
        else if ( m_dataType == FREE ) {
            pressFree(event);
        }
    }
}

void MyScene::mouseReleaseEvent(QMouseEvent *event) {
    m_mousePressed = false;
}

void MyScene::mouseMoveEvent(QMouseEvent *event) {
    if ( m_mousePressed ) {
        if ( m_dataType == LIGHTED ) {
            moveLighted(event);
        }
        else if ( m_dataType == FREE ) {
            moveFree(event);
        }
    }

}

void MyScene::pressLighted(QMouseEvent *event) {
    int col = m_grid.xToColumn(event->pos().x());
    int line = m_grid.yToLine(event->pos().y());
    m_grid.setLighted(line,col,m_dataSetter);

    redraw();
}

void MyScene::moveLighted(QMouseEvent *event) {
    int x = event->pos().x();
    int y = event->pos().y();
    int col = m_grid.xToColumn(x);
    int line = m_grid.yToLine(y);
    if ((m_grid.caseExist(line,col)) && (m_grid.getLighted(line,col) != m_dataSetter)) {
        m_grid.setLighted(line,col,m_dataSetter);
        redraw();
    }
}

void MyScene::pressFree(QMouseEvent *event) {
    int col = m_grid.xToColumn(event->pos().x());
    int line = m_grid.yToLine(event->pos().y());
    m_grid.setFree(line,col,!m_dataSetter);

    redraw();
}

void MyScene::moveFree(QMouseEvent *event) {
    int x = event->pos().x();
    int y = event->pos().y();
    int col = m_grid.xToColumn(x);
    int line = m_grid.yToLine(y);
    if ((m_grid.caseExist(line,col)) && (m_grid.getFree(line,col) == m_dataSetter)) {
        m_grid.setFree(line,col,!m_dataSetter);
        redraw();
    }
}

void MyScene::drawAmplResult(AmplResult result) {
    int line = result.getNbLine();
    int col = result.getNbColumn();
    const int MAX_S = 5;

    // On éfface l'écran:
    clear();

    // Affichage de la grille
    for(int l(0); l < line;++l) {
        int y = 32*l;
        this->addLine(0,y,32*col,y);
    }

    for(int c(0); c < col;++c) {
        int x = 32*c;
        this->addLine(x,0,x,32*line);
    }

    // On affiche le résultat de chaque case:
    for ( int l(0); l < line; ++l ) {
        for ( int c(0); c < col; ++c ) {

            double s = result.getS(l,c);
            int a = 255 - ( ( s / MAX_S ) * 255 );
            std::cout << a << std::endl;
            QColor color(0,0,0,a);
            QBrush brush(color);
            addRect(32*l,32*c, 32, 32, QPen(), brush);
        }
    }

    // On affiche les lampadaires:
    for ( int i = 0; i < result.getNbLight(); ++ i) {
        AmplLight light = result.getLight(i);
        if ( light.getP() > 0 ) {
            QColor color(255,255,0);
            QBrush brush(color);
            int x = 32 * light.getX();
            int y = 32 * light.getY();
            addEllipse(x,y,32,32,QPen(),brush);
        }
    }
}
