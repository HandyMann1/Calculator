#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class Calculator : public QWidget{
    Q_OBJECT
    public:
        Calculator(QWidget *parent = 0);

    private slots:
        void plus();
        void minus();
        void multiply();
        void divide();
        void equal();
        void clear();

        void add_digit(int digit);
        void change_to_first_number();
        void change_to_second_number();


    private:
        QLabel *first_number;
        QLabel *second_number;
        QLabel *result_number;
        QLabel *operation_sign;
        QLabel *choosen_number;
        bool is_first_number;
};
