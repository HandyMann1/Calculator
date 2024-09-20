#include "calc.h"
#include <QGridLayout>
#include <string>
PlusMinus::PlusMinus(QWidget * parent)
    : QWidget(parent){

    QPushButton *plus_btn = new QPushButton("+", this);
    QPushButton *minus_btn = new QPushButton("-", this);
    QPushButton *multiply_btn = new QPushButton("*", this);
    QPushButton *divide_btn = new QPushButton("/", this);

    QPushButton *add_one_btn = new QPushButton("1", this);
    QPushButton *add_two_btn = new QPushButton("2", this);
    QPushButton *add_three_btn = new QPushButton("3", this);
    QPushButton *add_four_btn = new QPushButton("4", this);
    QPushButton *add_five_btn = new QPushButton("5", this);
    QPushButton *add_six_btn = new QPushButton("6", this);
    QPushButton *add_seven_btn = new QPushButton("7", this);
    QPushButton *add_eight_btn = new QPushButton("8", this);
    QPushButton *add_nine_btn = new QPushButton("9", this);
    QPushButton *add_zero_btn = new QPushButton("0", this);
    lbl = new QLabel("0", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(plus_btn,0, 3);
    grid->addWidget(minus_btn, 1, 3);
    grid->addWidget(multiply_btn, 2, 3);
    grid->addWidget(divide_btn, 3, 3);

    grid->addWidget(add_one_btn, 0, 0);
    grid->addWidget(add_two_btn, 0, 1);
    grid->addWidget(add_three_btn, 0, 2);
    grid->addWidget(add_four_btn, 1, 0);
    grid->addWidget(add_five_btn, 1, 1);
    grid->addWidget(add_six_btn, 1, 2);
    grid->addWidget(add_seven_btn, 2, 0);
    grid->addWidget(add_eight_btn, 2, 1);
    grid->addWidget(add_nine_btn, 2, 2);
    grid->addWidget(add_zero_btn, 3, 1);

    grid->addWidget(lbl, 4, 2);

    setLayout(grid);

    connect(plus_btn, &QPushButton::clicked, this, &PlusMinus::plus);
    connect(minus_btn, &QPushButton::clicked, this, &PlusMinus::minus);
    connect(multiply_btn, &QPushButton::clicked, this, &PlusMinus::multiply);
    connect(divide_btn, &QPushButton::clicked, this, &PlusMinus::divide);

    connect(add_one_btn, &QPushButton::clicked, this, &PlusMinus::add_one);
    connect(add_two_btn, &QPushButton::clicked, this, &PlusMinus::add_two);
    connect(add_three_btn, &QPushButton::clicked, this, &PlusMinus::add_three);
    connect(add_four_btn, &QPushButton::clicked, this, &PlusMinus::add_four);
    connect(add_five_btn, &QPushButton::clicked, this, &PlusMinus::add_five);
    connect(add_six_btn, &QPushButton::clicked, this, &PlusMinus::add_six);
    connect(add_seven_btn, &QPushButton::clicked, this, &PlusMinus::add_seven);
    connect(add_eight_btn, &QPushButton::clicked, this, &PlusMinus::add_eight);
    connect(add_nine_btn, &QPushButton::clicked, this, &PlusMinus::add_nine);
    connect(add_zero_btn, &QPushButton::clicked, this, &PlusMinus::add_zero);
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
void PlusMinus::multiply(){
    int val = lbl->text().toInt();
    val = val*2;
    lbl->setText(QString::number(val));
}
void PlusMinus::divide(){
    int val = lbl->text().toInt();
    val = val/2;
    lbl->setText(QString::number(val));
}

void PlusMinus::add_number(int digit){
    int val = lbl->text().toInt();
    if (val == 0){
        lbl->setText(QString::number(digit));
    }
    else
    {
        std::string new_number = std::to_string(val) + std::to_string(digit);
        lbl->setText(QString::fromStdString(new_number));
    }
}
void PlusMinus::add_one(){
    add_number(1);
}
void PlusMinus::add_two(){
    add_number(2);
}
void PlusMinus::add_three(){
    add_number(3);
}
void PlusMinus::add_four(){
    add_number(4);
}
void PlusMinus::add_five(){
    add_number(5);
}
void PlusMinus::add_six(){
    add_number(6);
}
void PlusMinus::add_seven(){
    add_number(7);
}
void PlusMinus::add_eight(){
    add_number(8);
}
void PlusMinus::add_nine(){
    add_number(9);
}
void PlusMinus::add_zero(){
    add_number(0);
}

