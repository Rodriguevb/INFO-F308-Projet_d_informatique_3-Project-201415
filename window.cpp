#include "window.hpp"
#include "amplresult.hpp"

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

    QAction *execAmpl = new QAction("&Exécuter l'algorithme", this);
    menuFichier->addAction(execAmpl);

    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));


    QMenu *menuEdition = menuBar()->addMenu("&Edition");

    QAction *actionMap = new QAction("&Ajouter une carte", this);
    menuEdition->addAction(actionMap);

    QAction *actionGrid = new QAction("&Calculer la grille", this);
    menuEdition->addAction(actionGrid);

    QAction *actionEraser = new QAction("&Passer en mode effaceur", this);
    menuEdition->addAction(actionEraser);

    QAction *actionColor = new QAction("&Passer en mode coloriage", this);
    menuEdition->addAction(actionColor);

    QAction *actionPencil = new QAction("&Outil crayon", this);
    menuEdition->addAction(actionPencil);

    QAction *actionRectangle = new QAction("&Outil Rectangle", this);
    menuEdition->addAction(actionRectangle);

    QAction *actionLighted = new QAction("&Modifier les zones à éclairer", this);
    menuEdition->addAction(actionLighted);

    QAction *actionFree = new QAction("&Modifier les zones à bloquer", this);
    menuEdition->addAction(actionFree);

    QMenu *menuOption = menuBar()->addMenu("&Options");

    QAction *actionOptimize = new QAction("&Choix de l'optimisation", this);
    menuOption->addAction(actionOptimize);

    //connects
    connect(actionSauver, SIGNAL(triggered()), this, SLOT(save()));
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(open()));
    connect(execAmpl, SIGNAL(triggered()), this, SLOT(executeAmpl()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quit()));

    connect(actionMap, SIGNAL(triggered()), this, SLOT(addMap()));
    connect(actionGrid, SIGNAL(triggered()), this, SLOT(computeGrid()));
    connect(actionLighted, SIGNAL(triggered()), this, SLOT(setLight()));
    connect(actionFree, SIGNAL(triggered()), this, SLOT(setFree()));
    connect(actionEraser, SIGNAL(triggered()), this, SLOT(setEraser()));
    connect(actionColor, SIGNAL(triggered()), this, SLOT(setColor()));
    connect(actionPencil, SIGNAL(triggered()), this, SLOT(setPencil()));
    connect(actionRectangle, SIGNAL(triggered()), this, SLOT(setRectangle()));

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

void Window::setLight() {
    m_homepage->setDataType(MyScene::LIGHTED);
}

void Window::setFree() {
    m_homepage->setDataType(MyScene::FREE);
}

void Window::setEraser() {
    m_homepage->setDataSetter(false);
}

void Window::setColor() {
    m_homepage->setDataSetter(true);
}

void Window::setPencil() {
    m_homepage->setTool(MyScene::PENCIL);
}

void Window::setRectangle() {
    m_homepage->setTool(MyScene::RECTANGLE);
}

void Window::executeAmpl() {
    AmplResult result = m_ampllauncher.launch();
    m_homepage->drawAmplResult(result);
}
