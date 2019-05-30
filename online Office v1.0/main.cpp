#include "office.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/img/logo.ico"));
    Office w;
    w.show();
    return a.exec();
}
