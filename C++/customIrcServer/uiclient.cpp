#include "uiclient.h"


uiClient::uiClient(QTcpSocket *parent)
    :sock(parent)
    ,log(LOGTAGS_UI)
{

    QHostAddress myRemote = this->sock->peerAddress();
    this->log.setPrefix(myRemote.toString());
    this->log << "Initialized tcp client " << myRemote.toString() << endl;
    this->buffer = new QString();

    connect(this->sock, SIGNAL(disconnected()), SLOT(removeConnection()));
    connect(this->sock, SIGNAL(readyRead()),	SLOT(receiveMessage()));
}


void uiClient::send(QString data){
    this->sock->write(data.toStdString().c_str());
}

void uiClient::removeConnection(){
    this->log << "Connection lost" << endl;
    //Tell our parent class to remove this item
    emit this->disconnected(this);
}


jsonCommand uiClient::checkForJsonCommand(QByteArray &toAdd){
    int depth = 0;
    jsonCommand *newCommand;
    foreach(int b, toAdd){
        if(b == '{' || b == '['){
            depth++;
        }else if(b == '}' || b == ']'){
            depth--;
        }
        this->buffer->append(b);

        if(depth == 0){
            //Clear the buffer.
            newCommand = new jsonCommand(*this->buffer);
            this->log << "Data received: \t" << this->buffer << endl;
            this->buffer->clear();
            break;
        }
    }
    return *newCommand;
}

void uiClient::receiveMessage(){
    jsonCommand comm = this->checkForJsonCommand(this->sock->readAll());
    switch (comm.getCommand()) {
        case JSONCOMMAND_OWNCHAT:
            emit this->chatReceived(comm.getData("chat").toString());
            break;
        case JSONCOMMAND_USERQUERY:
            emit this->userQuery(this);
            break;
        case JSONCOMMAND_CHANGEOWNUSER:
            emit this->changeOwnUser(comm);
            break;
        case JSONCOMMAND_GETEVENTS:
            emit this->getEvents(this);
            break;
        default:
            break;
    }
}
