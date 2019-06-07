#include "office.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Office w;
    w.show();

    return a.exec();
}
