#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>

#include "demandview.hpp"
#include "resultview.hpp"
#include "backtrack.hpp"
#include "ampllauncher.hpp"

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    static const int AMPL_ALGO = 0;
    static const int BACKOPTI_ALGO = 1;
    static const int BACKFIRST_ALGO = 2;

    DemandView _viewLeft;
    ResultView _viewRight;
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
    QRadioButton _radioFree;
    std::vector< QString > _maps;
public:
    explicit MyMainWindow(QWidget *parent = 0);

    ~MyMainWindow();

private:
    void setUpUi();
    void setUpMaps();

    AmplResult createEmptyResult();
    bool isDemandAtZero();

signals:

private slots:
    void changeTool();
    void clearDemand();
    void execute();
    void changeMaps(int index);
};

#endif // MAINWINDOW_H
