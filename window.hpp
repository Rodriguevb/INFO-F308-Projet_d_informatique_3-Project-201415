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

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private:
    void Toolbar();
    HomePage *m_homepage;


private slots:
    void quit();
    void open();
    void save();
    void computeGrid();
    void addMap();
    void Optimize();
};

#endif // WINDOW_HPP
