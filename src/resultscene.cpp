#include "resultscene.hpp"

ResultScene::ResultScene(ResultView *view) :
    QGraphicsScene(view),
    _view(view)
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::drawResult(AmplResult result) {
    const int MAX_S = 6;

    // On éfface ce qu'il y a d'afficher à l'écran
    clear();

    // On dessine les lignes :
    for(int l(0); l < _view->SIZE;++l) {
        int y = CELL_SIZE*l;
        this->addLine(0,y,448,y);
    }

    // On dessine les colonnes
    for(int c(0); c < _view->SIZE;++c) {
        int x = CELL_SIZE*c;
        this->addLine(x,0,x,448);
    }

    // On affiche le résultat de chaque case:
    for ( int l(0); l < _view->SIZE; ++l ) {
        for ( int c(0); c < _view->SIZE; ++c ) {
            // On dessine le carré gris.
            double s = result.getS(l,c);
            int a = 255 - ( ( s / MAX_S ) * 255 );
            QColor color(0,0,0,a);
            QBrush brush(color);
            addRect(CELL_SIZE*l,CELL_SIZE*c, CELL_SIZE, CELL_SIZE, QPen(), brush);

            // On écrit les chiffres
            QGraphicsTextItem *text = new QGraphicsTextItem();
            text->setPos(CELL_SIZE*l + CELL_SIZE/4, CELL_SIZE *c + CELL_SIZE/4);
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
            int x = CELL_SIZE * (light.getX()-1);
            int y = CELL_SIZE * (light.getY()-1);
            addEllipse(x,y,CELL_SIZE,CELL_SIZE,QPen(),brush);
            str += "( %1 , %2 ) : P = %3 \n";
            str = str.arg(light.getX()).arg(light.getY()).arg(light.getP());
        }
    }

}

double ResultScene::roundDouble(double toround) {
    int entier = (int) ( (0.005 + toround) * 100.0 );
    return (double) (entier/100.0);
}
