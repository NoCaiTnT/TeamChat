#include "servers.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Servers w;
    w.runServers();
    return a.exec();
}
