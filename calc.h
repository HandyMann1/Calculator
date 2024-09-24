#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

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
        void remove();

        void add_digit(int digit);



    private:
        QLineEdit *written_number;



};
