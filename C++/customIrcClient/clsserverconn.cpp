#include "clsserverconn.h"
#include "../resources/jsoncommand.h"


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
                        SLOT(srvConnected()));
    this->sock->connect(this->sock, SIGNAL(disconnected()), this,
                        SLOT(srvDisconnected()));
}

void clsServerConn::doConnect(){
    this->sock->connectToHost(this->hostName,this->port);
    this->log << "Connecting" << endl;
}

void clsServerConn::sendCommand(jsonCommand &toSend){
    //this->log << "Sending json object: " << docToSend->toJson() << endl;
    this->log << "Sending JSON: " << toSend << endl;
    QByteArray bAToSend;
    bAToSend.append(toSend.toJsonString() + "\r\n");
    this->sock->write(bAToSend);
}

void clsServerConn::srvConnected(){
    this->log << "Connected!" << endl;
    emit this->connected();
}


void clsServerConn::srvDisconnected(){
    this->log << "Disconnected" << endl;
    emit this->disconnected();
}

void clsServerConn::handleCompletedQuery(jsonCommand *comm){
    QVector<ircUser*> users;
    foreach(QVariant user, comm->getData("users").toList()){
        users.append(new ircUser(user));
    }
    emit this->userQueryCompleted(users);
}

void clsServerConn::handleUserInfo(jsonCommand *command){
    if(command->getData("change") == "STATUS"){
        emit this->userStatusChange(command->getData("user").toInt(),
                                    command->getData("new").toString());
    }else if(command->getData("change") == "LEAVE"){
        emit this->userLeave(command->getData("user").toInt());
    }else if(command->getData("change") == "ENTER"){
        emit this->userEnter(new ircUser(command->getData("user")));
    }else if(command->getData("change") == "NICK"){
        emit this->userChangeNick(command->getData("user").toInt(),
                                   command->getData("new").toString());
    }
}

void clsServerConn::handleOwnUserChange(jsonCommand *comm){
    //This function might have the same body as handleUserInfo.
    //But for now this is the only thing changeable.
    //Maybe later there will be more stuff added here
    if(comm->getData("change") == "STATUS"){
        //Own user is always ID 1..
        emit this->userStatusChange(1, comm->getData("new").toString());
    }
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
            emit this->chatReceived(comm.getData("user").toInt(),
                                    comm.getData("chat").toString());
            break;
        case JSONCOMMAND_USERQUERY:
            this->handleCompletedQuery(&comm);
            break;
        case JSONCOMMAND_USERINFO:
            this->handleUserInfo(&comm);
            break;
        case JSONCOMMAND_CHANGEOWNUSER:
            this->handleOwnUserChange(&comm);
            break;
        default:
            break;
        }
    }
}
