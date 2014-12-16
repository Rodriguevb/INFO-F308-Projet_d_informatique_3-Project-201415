#include "optiondialog.hpp"

OptionDialog::OptionDialog(QWidget *parent) : QDialog(parent)
{
    QGridLayout *mainLayout = new QGridLayout();
    QGroupBox *groupBox = new QGroupBox(tr("Choose your optimization"));
    QVBoxLayout *layout = new QVBoxLayout();
    optimum = new QRadioButton("Eclairage optimum", this);
    optimum->setChecked(true);
    ecologique = new QRadioButton("Eclairage ecologique", this);
    maximum = new QRadioButton("Eclairage maximum", this);
    economique = new QRadioButton("Eclairage economique", this);
    securitaire = new QRadioButton("Eclairage securitaire", this);

    layout->addWidget(optimum);
    layout->addWidget(ecologique);
    layout->addWidget(maximum);
    layout->addWidget(economique);
    layout->addWidget(securitaire);

    groupBox->setLayout(layout);

    mainLayout->addWidget(groupBox,0,0);

    this->setLayout(mainLayout);
    this->setWindowTitle("Optimize lighting");

}
