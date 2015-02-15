#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include "homepage.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include "optiondialog.hpp"
#include "ampllauncher.hpp"

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private:
    void Toolbar();
    HomePage *m_homepage;
    OptionDialog *m_option;
    AmplLauncher m_ampllauncher;


private slots:
    void quit();
    void open();
    void save();
    void computeGrid();
    void addMap();
    void Optimize();
    void setLight();
    void setFree();
    void setEraser();
    void setColor();
    void setPencil();
    void setRectangle();
    void executeAmpl();
};

#endif // WINDOW_HPP
