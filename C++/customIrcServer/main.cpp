// main.cpp
#include <stdlib.h>
#include <iostream>
#include <QtCore>
#include "mainapp.h"

using namespace server;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    mainApp mApp(a.applicationDirPath(),&a);


    mApp.run();
    return a.exec();
}
