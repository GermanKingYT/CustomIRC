#include <iostream>
#include <stdlib.h>
#include "ircclient.h"

using namespace std;

ircClient::ircClient(const char *hostname, const int port)
    :hostname(QString(hostname))
    ,port(port)
{
    this->init();
}

ircClient::ircClient(const char *hostname)
    :hostname(QString(hostname))
    ,port(this->PORT)
{
    this->init();
}

void ircClient::init(){
    doLog(this->TAG, "Initializing IRC client for host %s:%i", this->hostname.toStdString().c_str(),this->port);

    this->sock = new QTcpSocket(this);
    this->sock->connect(this->sock, SIGNAL(readyRead()), this, SLOT(readData()));
    this->sock->connect(this->sock, SIGNAL(connected()), this, SLOT(connected()));
    this->sock->connect(this->sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void ircClient::disconnected(){
    doLog(this->TAG, "Disconnected");
}

ircClient::~ircClient(){
}

void ircClient::connect(){
    doLog(this->TAG, "Connecting");
    this->sock->connectToHost(this->hostname,this->port);
}

void ircClient::connected(){
    doLog(this->TAG, "Connected!");
}


void ircClient::readData(){
    doLog(this->TAG, "Data ready");
    QByteArray data = this->sock->readAll();
    doLog(this->TAG, "Data received: %s",fromQstringToCharArray(QString(data)));

}
