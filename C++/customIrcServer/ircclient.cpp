#include <iostream>
#include <stdlib.h>
#include "ircclient.h"

using namespace std;

ircClient::ircClient(const char *hostname, const int port)
    :hostname(QString(hostname))
    ,port(port)
    ,channel(CHANNEL)
    ,log(clsLog(LOGTAGS_IRC))
{
    this->ownNickAndStatus.nick = NICK;
    this->init();
}

ircClient::ircClient(const char *hostname, const char *channel)
    :hostname(QString(hostname))
    ,port(this->PORT)
    ,channel(QString(channel))
    ,log(clsLog(LOGTAGS_IRC))
{
    this->ownNickAndStatus.nick = NICK;
    this->init();
}

ircClient::ircClient(const char *hostname, const char *channel, const char *nick)
    :hostname(QString(hostname))
    ,port(this->PORT)
    ,channel(QString(channel))
    ,log(clsLog(LOGTAGS_IRC))
{
    this->ownNickAndStatus.nick = nick;
    this->init();
}

ircClient::ircClient(const char *hostname, const int port, const char *channel
                     ,const char *nick)
    :hostname(QString(hostname))
    ,port(port)
    ,channel(QString(channel))
    ,log(clsLog(LOGTAGS_IRC))
{
    this->ownNickAndStatus.nick = nick;
    this->init();
}

ircClient::ircClient(const char *hostname)
    :hostname(QString(hostname))
    ,port(this->PORT)
    ,channel(QString(CHANNEL))
    ,log(clsLog(LOGTAGS_IRC))
{
    this->ownNickAndStatus.nick = NICK;
    this->init();
}

void ircClient::init(){
    this->log << "Initializing IRC Client for host " << this->hostname << ":";
    this->log << this->port << endl;

    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

    this->sock = new QTcpSocket(this);
    this->sock->connect(this->sock, SIGNAL(readyRead()), this,
                        SLOT(readData()));
    this->sock->connect(this->sock, SIGNAL(connected()), this,
                        SLOT(connected()));
    this->sock->connect(this->sock, SIGNAL(disconnected()), this,
                        SLOT(disconnected()));
}

void ircClient::disconnected(){
    this->log << "Disconnected" << endl;
}

ircClient::~ircClient(){
    buffer->close();
    this->sock->close();
}

void ircClient::connect(){
    //doLog(this->TAG, "Connecting");
    this->log << "Connecting" << endl;
    this->sock->connectToHost(this->hostname,this->port);
}

void ircClient::connected(){
    //doLog(this->TAG, "Connected!");
    this->send(QString("USER %1 0 * :%1").arg(this->ownNickAndStatus.nick));
    this->send(QString("NICK %1").arg(this->ownNickAndStatus.nick));
}



void ircClient::handleCommand(const QString &sender, const QStringList &command){
    if(sender == this->hostname){
        //Message from the server:
        ircCodes::ircCode code = (ircCodes::ircCode) atoi(qts(command[0]).c_str());
        QString userNick;
        QString userId;
        switch (code) {
        case ircCodes::RPL_ENDOFMOTD:
        case ircCodes::ERR_NOMOTD:
            //OH YES!
            this->motdReceived = true;
            this->send(QString("JOIN #%1").arg(this->channel));
            break;
         case ircCodes::RPL_WHOREPLY:
            //Create ID
            if(inCommand(&command[2],qts(this->channel).c_str())){
                userNick = command[6];
                if(userNick != this->ownNickAndStatus.nick){
                    userId = userNick + "!" + command[2] + "@" + command[3];
                    emit this->userOnline(getNickAndStatus(userNick),userId,
                                          this->channel);
                }
            }
            break;
         default:
            break;
        }
    }else{ //Probably a user:
        if(command[0] == "PRIVMSG"){
            //Yep, it is!
            QStringList args = command;
            args.pop_front();
            QString channel = args[0];
            args.pop_front();

            emit this->chatReceived(channel, getNickAndStatus(sender), args.join(" ").mid(1));
        }else if(command[0] == "NICK"){
            //Somebody changed nick!
            if(getNickAndStatus(sender).nick == "KoeBot"){

            }else{
                if(getNickAndStatusFromId(sender).nick ==
                        getNickAndStatus(command[1]).nick){
                    //Probably a status change:
                    emit this->userChangeStatus(getNickAndStatusFromId(sender),
                                                getNickAndStatus(command[1]),
                            getId(sender));
                }else{
                    emit this->userChangeNick(getNickAndStatusFromId(sender),
                                              getNickAndStatus(command[1]),
                            getId(sender));
                }
            }
        }else if(command[0] == "JOIN"){
            //Somebody joined, goody! :D
            if(getNickAndStatusFromId(sender).nick == "KoeBot"){
                //We have succesfully joined the channel
                //Yay, we can save our own ID.
                //Also, get a list of all the people in there
                this->send("WHO");
            }else{
                emit this->userOnline(getNickAndStatusFromId(sender), sender,
                                      command[1].mid(1));
            }
        }else if(command[0] == "PART"){
            if(getNickAndStatusFromId(sender).nick == "KoeBot"){
            }else{
                emit this->userOffline(getNickAndStatusFromId(sender), sender,
                                       command[1]);
            }
        }
    }
}



void ircClient::sendChat(const char* msg, const char* channel){
    QString cmd = "PRIVMSG #" + QString(channel) + " :" + QString(msg);
    this->send(qts(cmd).c_str());

    emit this->chatReceived(QString(channel),this->ownNickAndStatus,QString(msg));
}

void ircClient::sendChat(const char *msg){
    QString cmd = "PRIVMSG #" + this->channel + " :" + QString(msg);
    this->send(qts(cmd).c_str());
    emit this->chatReceived(QString(channel),this->ownNickAndStatus,QString(msg));
}

void ircClient::sendChat(const QString &msg){
    QString cmd = "PRIVMSG #" + this->channel + " :" + QString(msg);
    this->send(qts(cmd).c_str());
    emit this->chatReceived(QString(channel),this->ownNickAndStatus,QString(msg));
}

nickAndStatus ircClient::getOwnNick() const{
    return this->ownNickAndStatus;
}


void ircClient::send(const QString data){
    //doLog(this->TAG, "Sending data: \t%s",data);
    this->log << "Sending data: \t" << data << endl;
    this->sock->write(qts(data).c_str());
    this->sock->write("\r\n");
    this->sock->flush();
}

void ircClient::send(const char *data){
    //doLog(this->TAG, "Sending data: \t%s",data);
    this->log << "Sending data: \t" << data << endl;
    this->sock->write(data);
    this->sock->write("\r\n");
    this->sock->flush();
}

void ircClient::readData(){
    qint64 bytes = this->buffer->write(this->sock->readAll());
    this->buffer->seek(this->buffer->pos() - bytes);
    // read only full lines, line by line
    while (this->buffer->canReadLine()){
        QString line = this->buffer->readLine();
        line = line.simplified();
        //doLog(this->TAG, "Data received: \t%s",qts(line).c_str());
        this->log << "Data received: \t" << line << endl;
        if(line.left(4) == QString("PING")){
            //Send a pong:
            QString toSend = "PONG" + line.mid(4);
            this->send(qts(toSend).c_str());
        }else if(line.left(5) == QString("ERROR")){
            //Handle.. once :P
        }else{
            line = line.mid(1);
            QStringList commandList = line.split(" ");
            QString sender = commandList.at(0);
            commandList.pop_front(); // Remove the sender

            this->handleCommand(sender,commandList);

        }
    }
}



