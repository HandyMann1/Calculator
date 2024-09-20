#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class PlusMinus : public QWidget{
    Q_OBJECT
    public:
        PlusMinus(QWidget *parent = 0);

    private slots:
        void plus();
        void minus();
        void multiply();
        void divide();

        void add_number(int digit);

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
        QLabel *lbl;
};
