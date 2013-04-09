#include "mainapp.h"

namespace server {

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
    this->ui = new uiServer(this->settings->getListeningPort(), this);

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

	connect(this->irc, SIGNAL(IRCConnectTimeOut()), this, SLOT(ircConnectTimeOut()));
	connect(this->irc, SIGNAL(IRCConnected()), this, SLOT(ircConnected()));
	connect(this->irc, SIGNAL(IRCDisconnected(QString)), this,
			SLOT(ircDisconnected(QString)));

    connect(this->ui,SIGNAL(sgnChatReceived(QString)),this,SLOT(uiSendChat(QString)));
    connect(this->ui,SIGNAL(sgnUserQuery(uiClient*)), this,SLOT(doUserQuery(uiClient*)));
    connect(this->ui, SIGNAL(sgnSendEvents(uiClient*)), this, SLOT(doSendEvents(uiClient*)));
    connect(this->ui,SIGNAL(sgnChangeOwnUserStatus(QString)),
            this, SLOT(ownUserChangeStatus(QString)));


    //Init db of 'standard' irc users:
    ownUser = this->settings->getOwnUser();
    ownUser->setOnline(true);
    ownUser->setStatus("");
	this->irc->setOwnUser(ownUser);
    this->users->add(ownUser);
    foreach(ircUser* user, this->settings->getUsers()){
        this->users->add(user);
    }

	this->serverMessage("Connecting to irc.", SERVERMESSAGE_LEVEL_INFO);
	this->irc->doConnect();
	this->ui->startListen();
}

void mainApp::addToEventHistory(clsEvent *event){
	this->events.append(event);
	while(this->events.count() > MAX_EVENTS){
		this->events.pop_front();
	}
}

void mainApp::chatReceived(const QString channel, const nickAndStatus user,
                           const QString message){
    Q_UNUSED(channel);
    this->log << "Chat received:\t<" << user.nick << ">\t" << message << endl;

    //Create event:
    eventChat *chatEvent = new eventChat(
                this->users->getUserByNick(user)->getId(), message);

	this->addToEventHistory(chatEvent);
    jsonCommand chatMessage(JSONCOMMAND_EVENT);
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
    //Create event
    eventUserJoin *joinEvent = new eventUserJoin(
                user->getId(),user->toVariantMap());
	this->addToEventHistory(joinEvent);
    jsonCommand uUser(JSONCOMMAND_EVENT);

    uUser.addToData("event",joinEvent->toVariant());
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

		//Create event
		eventUserLeave *leaveEvent = new eventUserLeave(
					user->getId());
		this->addToEventHistory(leaveEvent);
		jsonCommand uUser(JSONCOMMAND_EVENT);

		uUser.addToData("event",leaveEvent->toVariant());
		this->ui->send(uUser);
    }
}

void mainApp::userChangeNick(const nickAndStatus oldNick,
							 const nickAndStatus newNick, const QString id){
	this->log << oldNick.nick << " changed nick to " << newNick.nick << endl;

	ircUser *user = this->users->getUser(oldNick, id);
    if(user->getName() == "NaN"){
        //Say WHAT!?
		this->log << oldNick.nick << " bestaat niet!?" << endl;
    }else{
		user->setNick(newNick.nick);

		//Create event
		eventUserChangeNick *changeEvent = new eventUserChangeNick(
					user->getId(),
					newNick.nick,
					oldNick.nick);
		this->addToEventHistory(changeEvent);
		jsonCommand uUser(JSONCOMMAND_EVENT);

		uUser.addToData("event",changeEvent->toVariant());
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
		//Create event
		eventUserChangeStatus *changeEvent = new eventUserChangeStatus(
					user->getId(),
					newNick.status,
					oldNick.status);
		this->addToEventHistory(changeEvent);
		jsonCommand uUser(JSONCOMMAND_EVENT);

		uUser.addToData("event",changeEvent->toVariant());
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

void mainApp::serverMessage(const QString &message, const level lvl){
	eventServerMessage *myMessage = new
			eventServerMessage(message, lvl);

	jsonCommand eventMsg(JSONCOMMAND_EVENT);

	eventMsg.addToData("event",myMessage->toVariant());
	this->ui->send(eventMsg);
	this->addToEventHistory(myMessage);
}

void mainApp::ircConnectTimeOut(){
	this->serverMessage(
				QString("Connection to IRC failed. Reconnecting in %1 seconds").
						arg(qint32(RECONNECT_IN_S)), SERVERMESSAGE_LEVEL_ERROR);

	//Now, let's reconnect in RECONNECT_IN_S
	this->reconnectTimer.singleShot(RECONNECT_IN_S*1000, this,
									SLOT(doIrcReconnect()));
}

void mainApp::ircConnected(){
	this->serverMessage("Connected to IRC!", SERVERMESSAGE_LEVEL_INFO);
}

void mainApp::ircDisconnected(QString reason){
	QString msg("Disconnected from IRC: %1. Reconnecting in %2 seconds");
	msg = msg.arg(reason, qint32(RECONNECT_IN_S));

	this->serverMessage(msg, SERVERMESSAGE_LEVEL_ERROR);
	//Reconnect in RECONNECT_IN_S
	this->reconnectTimer.singleShot(RECONNECT_IN_S*1000, this,
									SLOT(doIrcReconnect()));
}

void mainApp::doIrcReconnect(){
	this->serverMessage("Reconnecting", SERVERMESSAGE_LEVEL_INFO);
	this->irc->doConnect();
}

}
