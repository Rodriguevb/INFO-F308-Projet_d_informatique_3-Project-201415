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
    drawAmplResult(generateDemand(),false);
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

void MyScene::drawAmplResult(AmplResult result, bool showLight) {
    int line = result.getNbLine();
    int col = result.getNbColumn();
    int caseSize = 64;
    const int MAX_S = 3;

    // On éfface l'écran:
    clear();

    // Affichage de la grille
    for(int l(0); l < line;++l) {
        int y = caseSize*l;
        this->addLine(0,y,caseSize*col,y);
    }

    for(int c(0); c < col;++c) {
        int x = caseSize*c;
        this->addLine(x,0,x,caseSize*line);
    }

    // On affiche le résultat de chaque case:
    for ( int l(0); l < line; ++l ) {
        for ( int c(0); c < col; ++c ) {
            // On dessine le carré gris.
            double s = result.getS(l,c);
            int a = 255 - ( ( s / MAX_S ) * 255 );
            QColor color(0,0,0,a);
            QBrush brush(color);
            addRect(caseSize*l,caseSize*c, caseSize, caseSize, QPen(), brush);

            // On écrit les chiffres
            QGraphicsTextItem *text = new QGraphicsTextItem();
            text->setPos(caseSize*l + caseSize/4, caseSize *c + caseSize/4);
            text->setPlainText(QString("%1").arg(roundDouble(s)));
            addItem(text);
        }
    }

    // On affiche les lampadaires:
    QString str = "";
    for ( int i = 0; i < result.getNbLight(); ++ i) {
        AmplLight light = result.getLight(i);
        if ( light.getP() > 0 ) {
            QColor color(255,255,0,100);
            QBrush brush(color);
            int x = caseSize * light.getX();
            int y = caseSize * light.getY();
            addEllipse(x,y,caseSize,caseSize,QPen(),brush);
            str += "( %1 , %2 ) : P = %3 \n";
            str = str.arg(light.getX()).arg(light.getY()).arg(light.getP());
        }
    }
    if ( showLight ) {
        QMessageBox msgBox;
        msgBox.setText("Puissance des lampadaires");
        msgBox.setInformativeText(str);
        msgBox.exec();
    }
}


double MyScene::roundDouble(double toround) {
    int entier = (int) ( (0.005 + toround) * 100.0 );
    return (double) (entier/100.0);
}

AmplResult MyScene::generateDemand() {
    AmplResult result;
    std::vector<float> line;
    line.push_back(2.10);
    line.push_back(2.40);
    line.push_back(2.40);
    line.push_back(2.30);
    line.push_back(2.20);
    line.push_back(1.60);
    line.push_back(0.50);
    result.addMatrixLine(line);

    line.clear();
    line.push_back(2.40);
    line.push_back(2.50);
    line.push_back(2.60);
    line.push_back(2.40);
    line.push_back(2.30);
    line.push_back(1.60);
    line.push_back(0.50);
    result.addMatrixLine(line);

    line.clear();
    line.push_back(2.40);
    line.push_back(2.60);
    line.push_back(2.50);
    line.push_back(2.40);
    line.push_back(2.40);
    line.push_back(1.70);
    line.push_back(0.60);
    result.addMatrixLine(line);

    line.clear();
    line.push_back(2.40);
    line.push_back(2.40);
    line.push_back(2.50);
    line.push_back(2.50);
    line.push_back(2.50);
    line.push_back(1.80);
    line.push_back(0.60);
    result.addMatrixLine(line);

    line.clear();
    line.push_back(2.30);
    line.push_back(2.40);
    line.push_back(2.40);
    line.push_back(2.60);
    line.push_back(2.50);
    line.push_back(1.90);
    line.push_back(0.60);
    result.addMatrixLine(line);

    line.clear();
    line.push_back(1.70);
    line.push_back(1.70);
    line.push_back(1.70);
    line.push_back(1.80);
    line.push_back(1.90);
    line.push_back(1.20);
    line.push_back(0.50);
    result.addMatrixLine(line);

    line.clear();
    line.push_back(0.60);
    line.push_back(0.60);
    line.push_back(0.60);
    line.push_back(0.60);
    line.push_back(0.60);
    line.push_back(0.50);
    line.push_back(0.00);
    result.addMatrixLine(line);

    return result;
}
