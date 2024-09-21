#include "login.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QMessageBox>
Login::Login(QWidget * parent)
    : QWidget(parent){
    QLabel *username_lbl = new QLabel("User Name");
    QLabel *password_lbl = new QLabel("Password");

    enter_username = new QLineEdit(this);
    enter_password = new QLineEdit(this);
    enter_password->setEchoMode(QLineEdit::Password);
    QPushButton *login_btn = new QPushButton("login");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(username_lbl,0,0);
    grid->addWidget(enter_username,0,1);
    grid->addWidget(password_lbl,1,0);
    grid->addWidget(enter_password,1,1);
    grid->addWidget(login_btn,2,1);


    setLayout(grid);
    connect(login_btn, &QPushButton::clicked, this, &Login::check_login_and_password);



    }
void Login::check_login_and_password(){
    QString username = enter_username->text();
    QString password = enter_password->text();
    QString correct_username = QString("test");
    QString correct_password = QString("test");
    if (username==correct_username && password==correct_password){
        emit login_successful();
        close();
    }
    else{
        QMessageBox::warning(this, "LOGIN ERROR!", "Wrong login or password!");
    }

}


