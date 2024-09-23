#include "calc.h"
#include <QGridLayout>
#include <string>
#include <QMessageBox>
#include <iostream>
Calculator::Calculator(QWidget * parent)
    : QWidget(parent){

    QPushButton *plus_btn = new QPushButton("+", this);
    QPushButton *minus_btn = new QPushButton("-", this);
    QPushButton *multiply_btn = new QPushButton("*", this);
    QPushButton *divide_btn = new QPushButton("/", this);
    QPushButton *equal_btn = new QPushButton("=", this);
    QPushButton *clear_btn = new QPushButton("Clear", this);

    const QString buttonLabels[] = { "0","1", "2", "3", "4", "5", "6", "7", "8", "9"};
    QPushButton *add_btn[10];
    for (const QString& label : buttonLabels) {
        std::cout << label.toStdString() << std::endl;
    }
    for(int i = 0; i < 10;i++){
        add_btn[i] = new QPushButton(buttonLabels[i], this);
    }


    QPushButton *choose_first_number_btn = new QPushButton("Choose first number", this);
    QPushButton *choose_second_number_btn = new QPushButton("Choose second number", this);

    first_number = new QLabel("0", this);
    second_number = new QLabel("0",this);
    result_number = new QLabel("0",this);
    operation_sign = new QLabel(".", this);
    choosen_number = new QLabel("first number chosen", this);

    bool is_first_number = true;

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(plus_btn,0, 3);
    grid->addWidget(minus_btn, 1, 3);
    grid->addWidget(multiply_btn, 2, 3);
    grid->addWidget(divide_btn, 3, 3);
    grid->addWidget(equal_btn, 3, 2);

    for(int i = 0; i <= 2; ++i){
        for (int j = 0; j <=2; ++j){
            grid->addWidget(add_btn[i*3 + j+1],i,j);
        }
    }



    grid->addWidget(add_btn[0], 3, 1);


    grid->addWidget(first_number, 4, 0);
    grid->addWidget(second_number, 4, 2);
    grid->addWidget(result_number, 4, 3);
    grid->addWidget(operation_sign, 4, 1);


    grid->addWidget(choose_first_number_btn,5,0);
    grid->addWidget(choose_second_number_btn,5,2);
    grid->addWidget(choosen_number,5,1);
    grid->addWidget(clear_btn, 5,3);
    setLayout(grid);

    connect(plus_btn, &QPushButton::clicked, this, &Calculator::plus);
    connect(minus_btn, &QPushButton::clicked, this, &Calculator::minus);
    connect(multiply_btn, &QPushButton::clicked, this, &Calculator::multiply);
    connect(divide_btn, &QPushButton::clicked, this, &Calculator::divide);
    connect(equal_btn, &QPushButton::clicked, this, &Calculator::equal);
    connect(clear_btn,&QPushButton::clicked, this, &Calculator::clear);

    for (int i = 0; i < 10; i++){

        connect(add_btn[i], &QPushButton::clicked, this,[this,i] {add_digit(i);});
     }

    connect(choose_first_number_btn, &QPushButton::clicked,this, &Calculator::change_to_first_number);
    connect(choose_second_number_btn, &QPushButton::clicked,this, &Calculator::change_to_second_number);
}




void Calculator::change_to_first_number(){
    choosen_number->setText(QString("first number chosen"));
    is_first_number = true;
}
void Calculator::change_to_second_number(){
    choosen_number->setText(QString("second number chosen"));
    is_first_number = false;
}
void Calculator::plus(){
    operation_sign->setText("+");
}
void Calculator::minus(){
    operation_sign->setText("-");
}
void Calculator::multiply(){
    operation_sign->setText("*");
}
void Calculator::divide(){
    operation_sign->setText("/");
}
void Calculator::equal(){
    if (operation_sign->text() == '.'){
        QMessageBox::about(this, "ERROR!", "Choose operation!");
    }
    else if (operation_sign->text() == "/" && second_number->text().toInt() == 0){
        QMessageBox::about(this, "DIVISION ERROR!", "You can't divide by zero!");
    }
    else if (operation_sign->text() == "+"){
        result_number->setText( QString::number(first_number->text().toInt() + second_number->text().toInt()));
    }
    else if (operation_sign->text() == "-"){
        result_number->setText(QString::number(first_number->text().toInt() - second_number->text().toInt()));
    }
    else if (operation_sign->text() == "*"){
        result_number->setText(QString::number(first_number->text().toInt() * second_number->text().toInt()));
    }
    else if (operation_sign->text() == "/"){
        result_number->setText(QString::number(first_number->text().toInt() / second_number->text().toInt()));
    }
}
void Calculator::clear(){
    first_number->setText(QString("0"));
    second_number->setText(QString("0"));
    result_number->setText(QString("0"));
    operation_sign->setText(QString("."));
}


void Calculator::add_digit(int digit){
    if(is_first_number){
        int val = first_number->text().toInt();
        if (val == 0){
            first_number->setText(QString::number(digit));
        }
        else
        {
            std::string new_number = std::to_string(val) + std::to_string(digit);
            first_number->setText(QString::fromStdString(new_number));
        }
    }
    else{
        int val = second_number->text().toInt();
        if (val == 0){
            second_number->setText(QString::number(digit));
        }
        else
        {
            std::string new_number = std::to_string(val) + std::to_string(digit);
            second_number->setText(QString::fromStdString(new_number));
        }
    }
}


