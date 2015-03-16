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
    _radioBlock(this)
{
    setUpUi();
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

    _buttonErase.setText("Effacer demande");
    _buttonErase.setGeometry(20,140,131,32);

    // On met en place les combobox et leurs label.
        // Choix de la map
    _mapLabel.setText("Choix de la carte :");
    _mapLabel.setGeometry(380,23,141,16);

    _mapCombo.setGeometry(520,20,341,26);
    _mapCombo.addItem("Carte 1");
    _mapCombo.addItem("Carte 2");

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

    _radioMedium.setText("Eclairage medium");
    _radioMedium.setGeometry(130,170,131,20);

    _radioLow.setText("Eclairage faible");
    _radioLow.setGeometry(262,170,121,20);

    _radioBlock.setText("Bloquer");
    _radioBlock.setGeometry(382,170,81,20);
}

