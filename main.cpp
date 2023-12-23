#include <QApplication>
#include "dbusclient.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    DbusClient w;

    w.show();

    return a.exec();
}
