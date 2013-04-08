#include "mainwindow.h"
#include <QApplication>

using namespace client;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&a);
#ifdef DESKTOP
    w.show();
#elif ANDROID
    w.setOrientation(MainWindow::ScreenOrientationAuto);
    w.showExpanded();
#endif

    return a.exec();
}
