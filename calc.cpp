#include "calc.h"
#include <QGridLayout>
#include <string>
#include <QMessageBox>
#include <QLineEdit>

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
    for(int i = 0; i < 10;i++){
        add_btn[i] = new QPushButton(buttonLabels[i], this);
    }

    written_number = new QLineEdit("0", this);
    written_number->setReadOnly(true);

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


    grid->addWidget(written_number, 4, 0,1,4);
    grid->setRowStretch(4,10);
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
}


void Calculator::plus(){
    QString val = written_number->text();
    if(val.endsWith(" + ") || val.endsWith(" - ") || val.endsWith(" / ") || val.endsWith(" * ")){
        val.chop(3);
    }
    val += " + ";
    written_number->setText(val);
}
void Calculator::minus(){
    QString val = written_number->text();
    if(val.endsWith(" + ") || val.endsWith(" - ") || val.endsWith(" / ") || val.endsWith(" * ")){
        val.chop(3);
    }
    val += " - ";
    written_number->setText(val);
}
void Calculator::multiply(){
    QString val = written_number->text();
    if(val.endsWith(" + ") || val.endsWith(" - ") || val.endsWith(" / ") || val.endsWith(" * ")){
        val.chop(3);
    }
    val += " * ";
    written_number->setText(val);
}
void Calculator::divide(){
    QString val = written_number->text();
    if(val.endsWith(" + ") || val.endsWith(" - ") || val.endsWith(" / ") || val.endsWith(" * ")){
        val.chop(3);
    }
    val += " / ";
    written_number->setText(val);
}
void Calculator::equal(){
    QString number = "";
    std::vector<std::string> numbers;
    std::vector<char> signs;
    QString val = written_number->text().remove(' ');
    for(int i = 0; i < val.length(); i++){
        QChar symbol = val.at(i);
        if (symbol.isDigit()){
            number.append(symbol);
        }
        else{
            signs.push_back(symbol.toLatin1());
            numbers.push_back(number.toStdString());
            number = "";
        }
    }
    if (!number.isEmpty()) {
        numbers.push_back(number.toStdString());
    }

    numbers.push_back("0");
    for(int i  = 0; i < signs.size(); i++){
        float num_1 = std::stof(numbers[0]);
        float num_2 = std::stof(numbers[i+1]);
        if (signs[i] == '+'){
            numbers[0] = std::to_string(num_1 + num_2);
        }
        else if(signs[i] == '-'){
            numbers[0] = std::to_string(num_1 - num_2);
        }
        else if(signs[i] == '*'){
            numbers[0] = std::to_string(num_1 * num_2);
        }
        else if(signs[i] == '/'){
            if (num_2 != 0){
                numbers[0] = std::to_string(num_1 / num_2);
            }
            else{
                QMessageBox::warning(this, "DIVISION ZERO ERROR!","YOU CANT DIVIDE BY ZERO!");
            }
        }
    }
    written_number->setText(QString::fromStdString(numbers[0]));
}

void Calculator::clear(){
    written_number->setText(QString("0"));
}


void Calculator::add_digit(int digit){
    std::string val = written_number->text().toStdString();
    if (val == "0"){
        written_number->setText(QString::number(digit));
    }
    else
    {
        std::string new_number = val + std::to_string(digit);
        written_number->setText(QString::fromStdString(new_number));
    }
}




