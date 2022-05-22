#include "kalaOKServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    kalaOKServer w;
    w.show();
    return a.exec();
}
