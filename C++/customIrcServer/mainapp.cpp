#include "mainapp.h"

mainApp::mainApp(QString parentPath, QObject *parent)
    :QObject(parent)
    ,users(new ircUserList())
    ,log(clsLog(LOGTAGS_MAIN))
{
    this->settings = new clsSettings(parentPath);
}


void mainApp::run(){
    this->log << "Starting up" << endl;

    this->irc = new ircClient(this->settings->getServer(),
                              this->settings->getChannel(),
                              this->settings->getUserName());
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

    connect(this->ui,SIGNAL(sgnChatReceived(QString)),this,SLOT(uiSendChat(QString)));
    connect(this->ui,SIGNAL(sgnUserQuery(uiClient*)), this,SLOT(doUserQuery(uiClient*)));

    //Init db of 'standard' irc users:
    ircUser *ownUser = this->settings->getOwnUser();
    this->users->add(ownUser);
    foreach(ircUser* user, this->settings->getUsers()){
        this->users->add(user);
    }


    this->irc->connect();
    this->ui->startListen();
}

void mainApp::chatReceived(const QString channel, const nickAndStatus user,
                           const QString message){
    this->log << "Chat received:\t<" << user.nick << ">\t" << message << endl;

    jsonCommand chatMessage(JSONCOMMAND_CHAT);

    chatMessage.addToData("user",
                          QVariant(
                              this->users->getUserByNick(user)->toVariantMap()));
    chatMessage.addToData("chat", message);
    chatMessage.addToData("channel", channel);

    this->ui->send(chatMessage);
}


void mainApp::userOnline(const nickAndStatus nick, const QString id, const QString channel){
    this->log << "Online\t" << nick.nick << "\t" << nick.status << endl;
    ircUser *user = this->users->getUser(nick,id);
    if(user->getName() == "NaN"){
        user = new ircUser(nick,id);
        this->users->add(user);
    }else{
        user->setStatus(nick.status);
        user->setOnline(true);
    }
    jsonCommand uUser(JSONCOMMAND_USERINFO);
    uUser.addToData("user",user->toVariantMap());
    uUser.addToData("change","STATE");
    this->ui->send(uUser);
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

        jsonCommand uUser(JSONCOMMAND_USERINFO);
        uUser.addToData("user",user->toVariantMap());
        uUser.addToData("change","STATE");
        this->ui->send(uUser);
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
        jsonCommand uUser(JSONCOMMAND_USERINFO);
        uUser.addToData("user",user->toVariantMap());
        uUser.addToData("change","STATUS");
        this->ui->send(uUser);
    }

}

void mainApp::uiSendChat(const QString message){
    this->irc->sendChat(message);
}

void mainApp::doUserQuery(uiClient *client){
    //Send all the users back
    jsonCommand uQuery(JSONCOMMAND_USERQUERY);
    QList<QVariant> users;
    foreach(ircUser *user, this->users->getAll()){
        users.append(QVariant(user->toVariantMap()));
    }
    uQuery.addToData("users",QVariant::fromValue(users));

    this->ui->send(client,uQuery);

}
