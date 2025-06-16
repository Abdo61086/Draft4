#include "mainwindow.h"
#include <QApplication>
#ifndef QT_TESTLIB_LIB
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
#endif
