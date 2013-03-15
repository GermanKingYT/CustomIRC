#include "mainapp.h"

mainApp::mainApp(QObject *parent)
    :QObject(parent)
    ,users(new ircUserList())
    ,log(clsLog(LOGTAGS_MAIN))
{
}


void mainApp::run(){
    this->log << "Starting up" << endl;
    this->irc = new ircClient("digi-online.net");
    this->ui = new uiServer(this);
    //this->irc = new ircClient("irc.k-4u.nl");
    //this->irc = new ircClient("localhost");

    connect(this->irc,SIGNAL(chatReceived(QString,nickAndStatus,QString)), this,
            SLOT(chatReceived(QString,nickAndStatus,QString)));

    connect(this->irc, SIGNAL(userOnline(nickAndStatus, QString, QString)), this,
            SLOT(userOnline(nickAndStatus, QString, QString )));

    connect(this->irc, SIGNAL(userOffline(nickAndStatus, QString, QString)), this,
            SLOT(userOffline(nickAndStatus, QString, QString )));


    connect(this->irc, SIGNAL(userChangeNick(nickAndStatus, nickAndStatus,
                                             QString))
            ,this,SLOT(userChangeNick(nickAndStatus,nickAndStatus,QString)));

    connect(this->irc, SIGNAL(userChangeStatus(nickAndStatus, nickAndStatus,
                                               QString))
            ,this, SLOT(userChangeStatus(nickAndStatus,nickAndStatus,QString)));

    //Init db of 'standard' irc users:
    this->users->add(new ircUser("Koenk",true));
    this->users->add(new ircUser("Joep",true));
    this->users->add(new ircUser("Jesper",true));
    this->users->add(new ircUser("BlueWolf",true));
    this->users->add(new ircUser("KoBe",true));

    //this->irc->connect();
    this->ui->startListen();
}

void mainApp::chatReceived(const QString channel, const nickAndStatus user,
                           const QString message){
    this->log << "Chat received:\t<" << user.nick << ">\t" << message << endl;
    //doLog(this->TAG,"Chat received: \t<%s>\t%s", qts(user).c_str(),
    //      qts(message).c_str());
    /*if(message == QString("who")){
        this->irc->sendChat("Gebruikers online:");
        foreach(ircUser user, this->users->getAll()){
            this->irc->sendChat(qts(QString(user.getName() + " Status: "
                                            + user.getStatus())).c_str());
        }
    }*/
}


void mainApp::userOnline(const nickAndStatus nick, const QString id, const QString channel){
    this->log << "Online\t" << nick.nick << "\t" << nick.status << endl;
    ircUser *user = this->users->getUser(nick,id);
    if(user->getName() == "NaN"){
        this->users->add(new ircUser(nick,id));
    }else{
        user->setStatus(nick.status);
        user->setOnline(true);
    }
}

void mainApp::userOffline(const nickAndStatus nick, const QString id, const QString channel){
    this->log << "Offline\t" << nick.nick << "\t" << nick.status << endl;
    ircUser *user = this->users->getUser(nick,id);
    if(user->getName() == "NaN"){
        //Say WHAT!?
        this->log << nick.nick << " bestaat niet!?" << endl;
    }else{
        user->setStatus("");
        user->setOnline(false);
        if(user->isStandard() == false){
            this->users->del(user);
        }
    }
}

void mainApp::userChangeNick(const nickAndStatus oldNickName,
                             const nickAndStatus newNickName, const QString id){
    this->log << oldNickName.nick << " changed nick to " << newNickName.nick << endl;

    ircUser *user = this->users->getUser(oldNickName,id);
    if(user->getName() == "NaN"){
        //Say WHAT!?
        this->log << oldNickName.nick << " bestaat niet!?" << endl;
    }else{
    }
}

void mainApp::userChangeStatus(const nickAndStatus oldNick,
                               const nickAndStatus newNick, const QString id){
    this->log << oldNick.nick << " changed status to " << newNick.status << endl;

    ircUser *user = this->users->getUser(oldNick,id);
    if(user->getName() == "NaN"){
        //Say WHAT!?
        this->log << oldNick.nick << " bestaat niet!?" << endl;
    }else{
        user->setStatus(newNick.status);
    }
}
