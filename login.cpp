#include "login.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
Login::Login(QWidget * parent)
    : QWidget(parent){
    QLabel *username_lbl = new QLabel("User Name");
    QLabel *password_lbl = new QLabel("Password");

    QLineEdit *enter_username = new QLineEdit;
    QLineEdit *enter_password = new QLineEdit;
    enter_password->setEchoMode(QLineEdit::Password);
    QPushButton *login = new QPushButton("login");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(username_lbl,0,0);
    grid->addWidget(enter_username,0,1);
    grid->addWidget(password_lbl,1,0);
    grid->addWidget(enter_password,1,1);
    grid->addWidget(login,2,1);


    setLayout(grid);
}
