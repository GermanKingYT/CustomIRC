#include "mainapp.h"

mainApp::mainApp(QObject *parent) :
    QObject(parent)
{
}


void mainApp::run(){
    doLog(this->TAG, "Starting up");
    irc = new ircClient("192.168.2.2");

    irc->connect();
}
