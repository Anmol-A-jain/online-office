#include "office.h"
#include <QApplication>
#include <Windows.h>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Office w;
    w.show();

    return a.exec();
}
