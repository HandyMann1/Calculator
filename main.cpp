#include "calc.h"
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calculator calc;
    Login w;
    w.resize(600,400);
    w.setWindowTitle("Calculator");
    w.show();
    return app.exec();
}


