#include "calc.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calculator w;
    w.resize(600,400);
    w.setWindowTitle("Calculator");
    w.show();
    return app.exec();
}


