#include "window.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.setWindowTitle("Optimisation de l'éclairage public");
    w.setFixedSize(800,600);
    w.show();

    return a.exec();
}
