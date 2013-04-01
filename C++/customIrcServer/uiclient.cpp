#include "uiclient.h"


uiClient::uiClient(QTcpSocket *parent)
    :sock(parent)
    ,log(LOGTAGS_UI)
{

    QHostAddress myRemote = this->sock->peerAddress();
    this->log.setPrefix(myRemote.toString());
    this->log << "Initialized tcp client " << myRemote.toString() << endl;
    this->buffer = new QBuffer();
    this->buffer->open(QIODevice::ReadWrite);
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

void uiClient::receiveMessage(){
    this->log << "Message received";

    // missing some checks for returns values for the sake of simplicity
    qint64 bytes = this->buffer->write(this->sock->readAll());
    // go back as many bytes as we just wrote so that it can be read
    this->buffer->seek(this->buffer->pos() - bytes);
    // read only full lines, line by line
    while (this->buffer->canReadLine()){
        QString line = this->buffer->readLine();
        line = line.simplified();
        this->log << line << endl;

        //Let' s just hope it received EVERYTHING
        //If not.. fuck
        jsonCommand comm(line);
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
            default:
                break;
        }
        //jsonCommand myCommand(QtJson::parse(line, isParsed).toMap());
        //this->log << myCommand << endl;
    }
}
