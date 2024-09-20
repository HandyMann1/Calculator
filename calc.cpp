#include "calc.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget * parent)
    : QWidget(parent){

    QPushButton *PlsBtn = new QPushButton("+", this);
    QPushButton *MinBtn = new QPushButton("-", this);
    lbl = new QLabel("0", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(PlsBtn,0,0);
    grid->addWidget(MinBtn, 0, 1);
    grid->addWidget(lbl, 1, 1);

    setLayout(grid);

    connect(PlsBtn, &QPushButton::clicked, this, &PlusMinus::plus);
    connect(MinBtn, &QPushButton::clicked, this, &PlusMinus::minus);
}
void PlusMinus::plus(){

    int val = lbl->text().toInt();
    val++;
    lbl->setText(QString::number(val));
}
void PlusMinus::minus(){
    int val = lbl->text().toInt();
    val--;
    lbl->setText(QString::number(val));
}
