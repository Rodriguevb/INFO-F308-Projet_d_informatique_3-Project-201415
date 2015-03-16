#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>

#include "demandview.hpp"

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    DemandView _viewLeft;
    QGraphicsView _viewRight;
    QPushButton _buttonCalculate;
    QPushButton _buttonErase;
    QLabel _mapLabel;
    QLabel _algoLabel;
    QComboBox _mapCombo;
    QComboBox _algoCombo;
    QRadioButton _radioHigh;
    QRadioButton _radioMedium;
    QRadioButton _radioLow;
    QRadioButton _radioBlock;
public:
    explicit MyMainWindow(QWidget *parent = 0);

    ~MyMainWindow();

private:
    void setUpUi();

signals:

public slots:
};

#endif // MAINWINDOW_H
