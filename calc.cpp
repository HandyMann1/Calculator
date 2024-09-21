#include "calc.h"
#include <QGridLayout>
#include <string>
#include <QMessageBox>

Calculator::Calculator(QWidget * parent)
    : QWidget(parent){

    QPushButton *plus_btn = new QPushButton("+", this);
    QPushButton *minus_btn = new QPushButton("-", this);
    QPushButton *multiply_btn = new QPushButton("*", this);
    QPushButton *divide_btn = new QPushButton("/", this);
    QPushButton *equal_btn = new QPushButton("=", this);
    QPushButton *clear_btn = new QPushButton("Clear", this);

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

    connect(add_one_btn, &QPushButton::clicked, this, &Calculator::add_one);
    connect(add_two_btn, &QPushButton::clicked, this, &Calculator::add_two);
    connect(add_three_btn, &QPushButton::clicked, this, &Calculator::add_three);
    connect(add_four_btn, &QPushButton::clicked, this, &Calculator::add_four);
    connect(add_five_btn, &QPushButton::clicked, this, &Calculator::add_five);
    connect(add_six_btn, &QPushButton::clicked, this, &Calculator::add_six);
    connect(add_seven_btn, &QPushButton::clicked, this, &Calculator::add_seven);
    connect(add_eight_btn, &QPushButton::clicked, this, &Calculator::add_eight);
    connect(add_nine_btn, &QPushButton::clicked, this, &Calculator::add_nine);
    connect(add_zero_btn, &QPushButton::clicked, this, &Calculator::add_zero);


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
void Calculator::add_one(){
    add_digit(1);
}
void Calculator::add_two(){
    add_digit(2);
}
void Calculator::add_three(){
    add_digit(3);
}
void Calculator::add_four(){
    add_digit(4);
}
void Calculator::add_five(){
    add_digit(5);
}
void Calculator::add_six(){
    add_digit(6);
}
void Calculator::add_seven(){
    add_digit(7);
}
void Calculator::add_eight(){
    add_digit(8);
}
void Calculator::add_nine(){
    add_digit(9);
}
void Calculator::add_zero(){
    add_digit(0);
}

