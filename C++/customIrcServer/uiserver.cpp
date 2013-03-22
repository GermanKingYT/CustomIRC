#include "uiserver.h"
#include <QBuffer>
#include <QTcpSocket>
#include <iostream>
#include <QDebug>

uiServer::uiServer(QObject* parent) : QTcpServer(parent), log(LOGTAGS_SERVER)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

uiServer::~uiServer(){ }

void uiServer::startListen(){
    this->log << "Started listening on port " << this->port << endl;
    this->listen(QHostAddress::Any,this->port);
}


void uiServer::send(jsonCommand &toSend){
    //this->log << "Sending json object: " << docToSend->toJson() << endl;
    this->log << "Sending JSON: " << toSend << endl;

    foreach(uiClient *cl, this->connections){
        cl->send(toSend.toJsonString() + "\r\n");
    }
}

void uiServer::acceptConnection(){
    uiClient *connection = new uiClient(this->nextPendingConnection());
    connect(connection, SIGNAL(disconnected(uiClient*)),
            this, SLOT(lostConnection(uiClient*)));
    connect(connection, SIGNAL(chatReceived(QString)),this,SLOT(chatReceived(QString)));
    connections.append(connection);
}

void uiServer::lostConnection(uiClient *client){
    this->connections.removeAll(client);
}

void uiServer::chatReceived(QString message){
    emit this->sgnChatReceived(message);
}
