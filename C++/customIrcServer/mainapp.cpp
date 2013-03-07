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
    //this->irc = new ircClient("irc.k-4u.nl");
    //this->irc = new ircClient("localhost");

    connect(this->irc,SIGNAL(chatReceived(QString,QString,QString)), this,
            SLOT(chatReceived(QString,QString,QString)));

    connect(this->irc, SIGNAL(userOnline(QString, QString)), this,
            SLOT(userOnline(QString, QString)));
    //Init db of 'standard' irc users:
    this->users->add(new ircUser("Koenk",true));
    this->users->add(new ircUser("Joep",true));
    this->users->add(new ircUser("Jesper",true));
    this->users->add(new ircUser("BlueWolf",true));
    this->users->add(new ircUser("KoBe",true));

    this->irc->connect();
}

void mainApp::chatReceived(const QString channel, const QString user, const QString message){
    this->log << "Chat received:\t<" << user << ":\t" << message << endl;
    //doLog(this->TAG,"Chat received: \t<%s>\t%s", qts(user).c_str(),
    //      qts(message).c_str());
    if(message == QString("who")){
        this->irc->sendChat("Gebruikers online:");
        foreach(ircUser user, this->users->getAll()){
            this->irc->sendChat(qts(QString(user.getName() + " Status: " + user.getStatus())).c_str());
        }
    }
}


void mainApp::userOnline(const QString nick, const QString id){
    ircUser *user = this->users->getUser(nick,id);
    if(user->getName() == "NaN"){
        //User doesn't exists..
        this->users->add(new ircUser(nick,id));
    }else{
        user->setStatus(getStatus(nick)[0]);
        user->setOnline(true);
        this->log << user->getName() << " is actief met status: "
                  << user->getStatus() << endl;
        //doLog(this->TAG,"%s is online gekomen: %s",qts(user->getName()).c_str(),
        //      qts(user->getStatus()).c_str());
    }
}
