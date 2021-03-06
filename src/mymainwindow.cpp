#include "mymainwindow.hpp"

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent),
    _viewLeft(this),
    _viewRight(this),
    _buttonCalculate(this),
    _buttonErase(this),
    _mapLabel(this),
    _algoLabel(this),
    _mapCombo(this),
    _algoCombo(this),
    _radioHigh(this),
    _radioMedium(this),
    _radioLow(this),
    _radioBlock(this),
    _radioFree(this),
    _maps()
{
    setUpUi();
    setUpMaps();
    _viewLeft.updateScene();
}

MyMainWindow::~MyMainWindow()
{

}

void MyMainWindow::setUpUi() {
    // Mise en place de la fenêtre principale.
    setFixedSize(1024,700);
    setWindowTitle("Optimisation de l'éclairage public");

    // Mise en place des vues.
    _viewLeft.setGeometry(20,200,448,448);
    _viewRight.setGeometry(556,200,448,448);

    // On met en place les boutons.
    _buttonCalculate.setText("Calculer");
    _buttonCalculate.setGeometry(470,400,81,32);
    connect(&_buttonCalculate, SIGNAL(clicked(bool)), this, SLOT(execute()));

    _buttonErase.setText("Effacer demande");
    _buttonErase.setGeometry(20,140,131,32);
    connect(&_buttonErase, SIGNAL(clicked(bool)), this, SLOT(clearDemand()));

    // On met en place les combobox et leurs label.
        // Choix de la map
    _mapLabel.setText("Choix de la carte :");
    _mapLabel.setGeometry(380,23,141,16);

    _mapCombo.setGeometry(520,20,341,26);
    _mapCombo.addItem("Carte LEGO");
    connect(&_mapCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeMaps(int)));

        // Choix de l'algo
    _algoLabel.setText("Choix de l'algorithme");
    _algoLabel.setGeometry(380,53,141,16);

    _algoCombo.setGeometry(520,50,341,26);
    _algoCombo.addItem("Optimal avec puissance variable");
    _algoCombo.addItem("Optimal avec puissance fixe");
    _algoCombo.addItem("Première solution acceptable (puissance fixe)");

    // On met en place les boutons radio
    _radioHigh.setText("Eclairage fort");
    _radioHigh.setGeometry(20,170,111,20);
    _radioHigh.setChecked(true);
    connect(&_radioHigh,SIGNAL(toggled(bool)),this,SLOT(changeTool()));

    _radioMedium.setText("Eclairage medium");
    _radioMedium.setGeometry(130,170,131,20);
    connect(&_radioMedium,SIGNAL(toggled(bool)),this,SLOT(changeTool()));

    _radioLow.setText("Eclairage faible");
    _radioLow.setGeometry(262,170,121,20);
    connect(&_radioLow,SIGNAL(toggled(bool)),this,SLOT(changeTool()));

    _radioBlock.setText("Bloqué");
    _radioBlock.setGeometry(382,170,81,20);
    connect(&_radioBlock,SIGNAL(toggled(bool)),this,SLOT(changeTool()));

    _radioFree.setText("Libre");
    _radioFree.setGeometry(382,150,81,20);
    connect(&_radioFree,SIGNAL(toggled(bool)),this,SLOT(changeTool()));
}

void MyMainWindow::setUpMaps() {
    _maps.push_back(QString("terrainlego.png"));

    _viewLeft.setMap(QString("terrainlego.png"));
    _viewRight.setMap(QString("terrainlego.png"));
}


void MyMainWindow::changeTool() {
    if ( _radioHigh.isChecked() ) {
        _viewLeft.setTool(DemandView::HIGH);
    } else if ( _radioMedium.isChecked() ) {
        _viewLeft.setTool(DemandView::MEDIUM);
    } else if ( _radioLow.isChecked() ) {
        _viewLeft.setTool(DemandView::LOW);
    } else if ( _radioBlock.isChecked() ) {
        _viewLeft.setTool(DemandView::BLOCKED);
    } else if ( _radioFree.isChecked() ) {
        _viewLeft.setTool(DemandView::FREE);
    }
}

void MyMainWindow::clearDemand() {
    _viewLeft.clearDemand();
}

void MyMainWindow::execute() {
    AmplResult result;
    int selected = _algoCombo.currentIndex();
    if ( isDemandAtZero() ) {
        _viewRight.drawResult(createEmptyResult());
    }
    else if ( selected == AMPL_ALGO ) {
        AmplLauncher ampl;
        result = ampl.launch(_viewLeft.getDemandGrid());
        _viewRight.drawResult(result, true);
    } else if ( selected == BACKOPTI_ALGO ) {
        Backtrack algo(_viewLeft.getDemandGrid(), _viewLeft.getFreeGrid(), 3);
        result = algo.executeOptimal();
        _viewRight.drawResult(result);
    } else if ( selected == BACKFIRST_ALGO ) {
        Backtrack algo(_viewLeft.getDemandGrid(), _viewLeft.getFreeGrid(), 3);
        result = algo.findAGoodSolution(0.35);
        _viewRight.drawResult(result);
    }
}

void MyMainWindow::changeMaps(int index) {
    _viewRight.setMap(_maps.at(index));
    _viewLeft.setMap(_maps.at(index));
    _viewLeft.updateScene();
}

AmplResult MyMainWindow::createEmptyResult() {
    AmplResult result;
    for ( int i(0); i < 7; ++i ) {
        std::vector<float> line;
        for ( int j(0); j < 7; ++j ) {
            line.push_back(0.f);
        }
        result.addMatrixLine(line);
    }
    return result;
}


bool MyMainWindow::isDemandAtZero() {
    std::vector < std::vector < float > > demand = _viewLeft.getDemandGrid();
    for ( int l(0); l < demand.size(); ++l) {
        for ( int c(0); c < demand.at(l).size(); ++c ) {
            if (demand.at(l).at(c) != 0.f) {
                return false;
            }
        }
    }

    return true;
}
