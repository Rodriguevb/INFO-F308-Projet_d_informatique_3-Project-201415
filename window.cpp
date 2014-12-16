#include "window.hpp"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    Toolbar();
    m_homepage = new HomePage(this);
    m_option = new OptionDialog(this);
    setCentralWidget(m_homepage);
}

Window::~Window()
{

}

void Window::Toolbar(){
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QAction *actionOuvrir = new QAction("&Ouvrir", this);
    menuFichier->addAction(actionOuvrir);
    actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));

    QAction *actionSauver = new QAction("&Sauvegarder", this);
    menuFichier->addAction(actionSauver);
    actionSauver->setShortcut(QKeySequence("Ctrl+S"));

    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));


    QMenu *menuEdition = menuBar()->addMenu("&Edition");

    QAction *actionMap = new QAction("&Ajouter une carte", this);
    menuEdition->addAction(actionMap);

    QAction *actionGrid = new QAction("&Calculer la grille", this);
    menuEdition->addAction(actionGrid);

    QMenu *menuOption = menuBar()->addMenu("&Options");

    QAction *actionOptimize = new QAction("&Choix de l'optimisation", this);
    menuOption->addAction(actionOptimize);

    //connects
    connect(actionSauver, SIGNAL(triggered()), this, SLOT(save()));
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(open()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quit()));

    connect(actionMap, SIGNAL(triggered()), this, SLOT(addMap()));
    connect(actionGrid, SIGNAL(triggered()), this, SLOT(computeGrid()));

    connect(actionOptimize, SIGNAL(triggered()), this, SLOT(Optimize()));
}

void Window::quit(){
    exit(0);
}

void Window::save(){
    // TODO
}

void Window::open(){
    //TODO
}

void Window::addMap(){
    qDebug() <<"add map from Image";
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
    m_homepage->setMap(fileName);
    update();
}

void Window::computeGrid(){
    qDebug() <<"Calcul grille";
    update();
}

void Window::Optimize(){
    m_option->show();
}
