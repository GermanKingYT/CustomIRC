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
    connect(this->ui, SIGNAL(sgnSendEvents(uiClient*)), this, SLOT(doSendEvents(uiClient*)));
    connect(this->ui,SIGNAL(sgnChangeOwnUserStatus(QString)),
            this, SLOT(ownUserChangeStatus(QString)));

    //Init db of 'standard' irc users:
    ownUser = this->settings->getOwnUser();
    ownUser->setOnline(true);
    ownUser->setStatus("");
    this->users->add(ownUser);
    foreach(ircUser* user, this->settings->getUsers()){
        this->users->add(user);
    }

    this->irc->connect();
    this->ui->startListen();
}

void mainApp::chatReceived(const QString channel, const nickAndStatus user,
                           const QString message){
    Q_UNUSED(channel);
    this->log << "Chat received:\t<" << user.nick << ">\t" << message << endl;

    //Create event:
    eventChat *chatEvent = new eventChat(
                this->users->getUserByNick(user)->getId(), message);

    this->events.append(chatEvent);
    jsonCommand chatMessage(JSONCOMMAND_CHAT);
    chatMessage.addToData("event",chatEvent->toVariant());

    this->ui->send(chatMessage);

}


void mainApp::userOnline(const nickAndStatus nick, const QString ircId, const QString channel){
    Q_UNUSED(channel);
    this->log << "Online\t" << nick.nick << "\t" << nick.status << endl;
    ircUser *user = this->users->getUser(nick, ircId);
    if(user->getName() == "NaN"){
        user = new ircUser(nick,ircId);
        this->users->add(user);
    }else{
        user->setStatus(nick.status);
        user->setOnline(true);
    }
    jsonCommand uUser(JSONCOMMAND_USERINFO);
    uUser.addToData("user",user->toVariantMap());
    uUser.addToData("change","ENTER");
    this->ui->send(uUser);
}

void mainApp::userOffline(const nickAndStatus nick, const QString id, const QString channel){
    Q_UNUSED(channel);
    this->log << "Offline\t" << nick.nick << "\t" << nick.status << endl;
    ircUser *user = this->users->getUser(nick, id);
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
        uUser.addToData("user",user->getId());
        uUser.addToData("change","LEAVE");
        this->ui->send(uUser);
    }
}

void mainApp::userChangeNick(const nickAndStatus oldNickName,
                             const nickAndStatus newNickName, const QString id){
    Q_UNUSED(id);
    this->log << oldNickName.nick << " changed nick to " << newNickName.nick << endl;

    ircUser *user = this->users->getUser(oldNickName, id);
    if(user->getName() == "NaN"){
        //Say WHAT!?
        this->log << oldNickName.nick << " bestaat niet!?" << endl;
    }else{
        user->setNick(newNickName.nick);

        jsonCommand uUser(JSONCOMMAND_USERINFO);
        uUser.addToData("user",user->getId());
        uUser.addToData("change","NICK");
        uUser.addToData("new",newNickName.nick);
        this->ui->send(uUser);
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
        uUser.addToData("user",user->getId());
        if(user->getStatus().toLower() == "offline"){
            uUser.addToData("change","OFFLINE");
            user->setOnline(false);
        }else{
            uUser.addToData("change","STATUS");
            uUser.addToData("new",user->getStatus());
            user->setOnline(true);
        }
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

void mainApp::doSendEvents(uiClient *client){
    jsonCommand toSend(JSONCOMMAND_GETEVENTS);
    QList<QVariant> events;
    foreach(clsEvent *ev, this->events){
        events.append(ev->toVariant());
    }
    toSend.addToData("events",QVariant(events));

    this->ui->send(client, toSend);
}

void mainApp::ownUserChangeStatus(QString newStatus){
    this->ownUser->setStatus(newStatus);
    if(newStatus == "Offline"){
        this->ownUser->setOnline(false);
    }else{
        this->ownUser->setOnline(true);
    }
    if(this->ownUser->getStatus() == ""){
        this->irc->setOwnNick(this->ownUser->getName());
    }else{
        this->irc->setOwnNick(this->ownUser->getName() + "|" +
                              this->ownUser->getStatus());
    }
}
