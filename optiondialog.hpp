#ifndef OPTIONDIALOG_HPP
#define OPTIONDIALOG_HPP

#include <QDialog>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QRadioButton>

class OptionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit OptionDialog(QWidget *parent = 0);

private :
    QRadioButton *optimum;
    QRadioButton *ecologique;
    QRadioButton *maximum;
    QRadioButton *economique;
    QRadioButton *securitaire;

signals:

public slots:

};

#endif // OPTIONDIALOG_HPP
