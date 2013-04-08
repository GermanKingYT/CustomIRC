#include "uiclient.h"

namespace server {

uiClient::uiClient(QTcpSocket *parent)
    :sock(parent)
    ,log(LOGTAGS_UI)
{

    QHostAddress myRemote = this->sock->peerAddress();
    this->log.setPrefix(myRemote.toString());
    this->log << "Initialized tcp client " << myRemote.toString() << endl;
    this->buffer = new QString();

    connect(this->sock, SIGNAL(disconnected()), SLOT(removeConnection()));
    connect(this->sock, SIGNAL(readyRead()),    SLOT(receiveMessage()));
}


void uiClient::send(QString data){
    this->sock->write(data.toStdString().c_str());
}

void uiClient::removeConnection(){
    this->log << "Connection lost" << endl;
    //Tell our parent class to remove this item
    emit this->disconnected(this);
}


bool uiClient::checkForJsonCommand(QByteArray toAdd, jsonCommand *comm){
    int depth = 0;
    bool ret = false;
    foreach(int b, toAdd){
        if(b == '{' || b == '['){
            depth++;
        }else if(b == '}' || b == ']'){
            depth--;
        }
        this->buffer->append(b);

        if(depth == 0){
            //Clear the buffer.
			if(comm->getCommand() == JSONCOMMAND_NONE){
				ret = true;
				comm = new jsonCommand(*this->buffer);
				this->log << "Data received: \t" << this->buffer << endl;
				this->buffer->clear();
			}
        }
    }
    return ret;
}

void uiClient::receiveMessage(){
    jsonCommand *comm = new jsonCommand(JSONCOMMAND_NONE);
    if(this->checkForJsonCommand(this->sock->readAll(), comm)){
        switch (comm->getCommand()) {
            case JSONCOMMAND_OWNCHAT:
                emit this->chatReceived(comm->getData("chat").toString());
                break;
            case JSONCOMMAND_USERQUERY:
                emit this->userQuery(this);
                break;
            case JSONCOMMAND_CHANGEOWNUSER:
                emit this->changeOwnUser(*comm);
                break;
            case JSONCOMMAND_GETEVENTS:
                emit this->getEvents(this);
                break;
            default:
                break;
        }
    }
}

}
