#include "uiserver.h"
#include <QBuffer>
#include <QTcpSocket>
#include <iostream>

uiServer::uiServer(QObject* parent) : QTcpServer(parent), log(LOGTAGS_SERVER)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

uiServer::~uiServer(){ }

void uiServer::startListen(){
    this->log << "Started listening on port " << this->port << endl;
    this->listen(QHostAddress::Any,this->port);
}

void uiServer::acceptConnection(){
    uiClient *connection = new uiClient(this->nextPendingConnection());
    connect(connection, SIGNAL(disconnected(uiClient*)),
            this, SLOT(lostConnection(uiClient*)));
    connections.append(connection);
}

void uiServer::lostConnection(uiClient *client){
    this->connections.removeAll(client);
}
