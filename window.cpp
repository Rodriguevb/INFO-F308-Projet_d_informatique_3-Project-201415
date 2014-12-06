#include "window.hpp"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    Toolbar();
    m_homepage = new HomePage(this);
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

    QAction *actionSommet = new QAction("&Ajouter un sommet", this);
    menuEdition->addAction(actionSommet);

    QAction *actionRoute = new QAction("&Ajouter une route", this);
    menuEdition->addAction(actionRoute);

    QMenu *menuOption = menuBar()->addMenu("&Options");

    QAction *actionOptimize = new QAction("&Choix de l'optimisation", this);
    menuOption->addAction(actionOptimize);

    //connects
    connect(actionSauver, SIGNAL(triggered()), this, SLOT(save()));
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(open()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quit()));

    connect(actionRoute, SIGNAL(triggered()), this, SLOT(addEdge()));
    connect(actionSommet, SIGNAL(triggered()), this, SLOT(addVertex()));

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

void Window::addEdge(){
    //TODO
}

void Window::addVertex(){
    Vertex *ver = new Vertex();
    ver->setText("Bruxelles");
    m_homepage->addVertex(ver);
    update();
}

void Window::Optimize(){
    //TODO
}
