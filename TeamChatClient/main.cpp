#include "login.h"
// #include "register.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // Register w;
    // w.show();

    Login w;
    w.show();
    int c = 0;
    return a.exec();
}
