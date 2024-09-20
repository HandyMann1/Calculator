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

        void add_one();
        void add_two();
        void add_three();
        void add_four();
        void add_five();
        void add_six();
        void add_seven();
        void add_eight();
        void add_nine();
        void add_zero();

    private:
        QLabel *first_number;
        QLabel *second_number;
        QLabel *result_number;
        QLabel *operation_sign;
        QLabel *choosen_number;
        bool is_first_number;
};
