#include "calc.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PlusMinus w;
    w.resize(400,400);
    w.setWindowTitle("PlusMinus");
    w.show();
    return app.exec();
}


