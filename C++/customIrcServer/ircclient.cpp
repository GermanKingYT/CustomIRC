#include <iostream>
#include <stdlib.h>
#include "ircclient.h"

using namespace std;

ircClient::ircClient(const char *hostname, const int port)
    :hostname(QString(hostname))
    ,port(port)
    ,channel(CHANNEL)
{
    this->init();
}

ircClient::ircClient(const char *hostname, const char *channel)
    :hostname(QString(hostname))
    ,port(this->PORT)
    ,channel(QString(channel))
{
    this->init();
}

ircClient::ircClient(const char *hostname, const int port, const char *channel)
    :hostname(QString(hostname))
    ,port(port)
    ,channel(QString(channel))
{
    this->init();
}

ircClient::ircClient(const char *hostname)
    :hostname(QString(hostname))
    ,port(this->PORT)
    ,channel(QString(CHANNEL))
{
    this->init();
}

void ircClient::init(){
    doLog(this->TAG, "Initializing IRC client for host %s:%i", qts(this->hostname).c_str(),this->port);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

    this->sock = new QTcpSocket(this);
    this->sock->connect(this->sock, SIGNAL(readyRead()), this, SLOT(readData()));
    this->sock->connect(this->sock, SIGNAL(connected()), this, SLOT(connected()));
    this->sock->connect(this->sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void ircClient::disconnected(){
    doLog(this->TAG, "Disconnected");
}

ircClient::~ircClient(){
    buffer->close();
    this->sock->close();
}

void ircClient::connect(){
    doLog(this->TAG, "Connecting");
    this->sock->connectToHost(this->hostname,this->port);
}

void ircClient::connected(){
    doLog(this->TAG, "Connected!");

    this->send("USER KoeBot 0 * :KoeBot");
    this->send("NICK KoeBot");

}

void ircClient::handleCommand(const QString &sender, const QStringList &command){
    if(sender == this->hostname){
        //Message from the server:
        ircCode code = (ircCode) atoi(qts(command[0]).c_str());
        QString userNick;
        QString userId;
        switch (code) {
        case RPL_ENDOFMOTD:
        case ERR_NOMOTD:
            //OH YES!
            this->motdReceived = true;
            this->send("JOIN #mattiechat");
            break;
         case RPL_WHOREPLY:
            //Create ID
            if(inCommand(&command[2],qts(this->channel).c_str())){
                userNick = command[6];
                if(userNick != "KoeBot"){
                    userId = userNick + "!" + command[2] + "@" + command[3];
                    emit this->userOnline(userNick,userId);
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

            emit this->chatReceived(channel,sender,args.join(" ").mid(1));
        }else if(command[0] == "NICK"){
            //Somebody changed nick!
        }else if(command[0] == "JOIN"){
            //Somebody joined, goody! :D
            if(this->getNicKFromId(sender) == "KoeBot"){
                //We have succesfully joined the channel
                //Yay, we can save our own ID.
                //Also, get a list of all the people in there
                this->send("WHO");
            }else{
                emit this->userOnline(this->getNicKFromId(sender), sender);
            }
        }
    }
}



void ircClient::sendChat(const char* msg, const char* channel){
    QString cmd = "PRIVMSG #" + QString(channel) + " :" + QString(msg);
    this->send(qts(cmd).c_str());
}

void ircClient::sendChat(const char *msg){
    QString cmd = "PRIVMSG #" + this->channel + " :" + QString(msg);
    this->send(qts(cmd).c_str());

}


void ircClient::send(const char* data){
    doLog(this->TAG, "Sending data: \t%s",data);
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
        doLog(this->TAG, "Data received: \t%s",qts(line).c_str());
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


const QString ircClient::getNicKFromId(const QString id){
    return id.left(id.indexOf("!"));
}


