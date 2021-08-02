#include "QBoards.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QBoards w;
    w.show();
    return a.exec();
}
