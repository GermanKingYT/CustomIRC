#include "clsserverconn.h"
#include "jsoncommand.h"


clsServerConn::clsServerConn(const QString hostName, const int port,
                             QObject *parent)
    :QObject(parent)
    ,hostName(hostName)
    ,port(port)
    ,log(LOGTAGS_UI)
{
    this->buffer = new QBuffer(this);
    this->buffer->open(QIODevice::ReadWrite);

    this->sock = new QTcpSocket(this);

    this->sock->connect(this->sock, SIGNAL(readyRead()), this,
                        SLOT(readData()));
    this->sock->connect(this->sock, SIGNAL(connected()), this,
                        SLOT(connected()));
    this->sock->connect(this->sock, SIGNAL(disconnected()), this,
                        SLOT(disconnected()));
}

void clsServerConn::doConnect(){
    this->sock->connectToHost(this->hostName,this->port);
    this->log << "Connecting" << endl;
}

void clsServerConn::sendCommand(jsonCommand &toSend){
    //this->log << "Sending json object: " << docToSend->toJson() << endl;
    this->log << "Sending JSON: " << toSend << endl;
    this->sock->write(QString(toSend.toJsonString() + "\r\n").toAscii());

}

void clsServerConn::connected(){
    this->log << "Connected!" << endl;
}


void clsServerConn::disconnected(){
    this->log << "Disconnected" << endl;
}


void clsServerConn::readData(){
    qint64 bytes = this->buffer->write(this->sock->readAll());
    this->buffer->seek(this->buffer->pos() - bytes);
    // read only full lines, line by line
    while (this->buffer->canReadLine()){
        QString line = this->buffer->readLine();
        line = line.simplified();
        //doLog(this->TAG, "Data received: \t%s",qts(line).c_str());
        this->log << "Data received: \t" << line << endl;
        //Let' s just hope it received EVERYTHING
        //If not.. fuck
        jsonCommand comm(line);
        switch (comm.getCommand()) {
        case JSONCOMMAND_CHAT:
            emit this->chatReceived(ircUser(comm.getData("user")),
                                    comm.getData("chat").toString());
            break;
        default:
            break;
        }
    }
}
