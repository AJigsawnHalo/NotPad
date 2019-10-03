#include "notpad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotPad w;
    w.show();
    return a.exec();
}
