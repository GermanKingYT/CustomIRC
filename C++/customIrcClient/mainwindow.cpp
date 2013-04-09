#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace client{

    MainWindow::MainWindow(QApplication *a, QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        log(LOGTAGS_UI),
        server()
    {
        this->settings = new clsSettings(a->applicationDirPath());
        this->server = new clsServerConn(settings->getServer(),settings->getPort());
        //this->server = new clsServerConn("localhost",1337);

        ui->setupUi(this);

        connect(this->ui->scrollArea->verticalScrollBar(),SIGNAL(rangeChanged(int,int)),
                this,SLOT(moveScrollBarToBottom(int,int)));


        connect(this->server, SIGNAL(chatReceived(eventChat*)),
                this, SLOT(chatReceived(eventChat*)));
        connect(this->ui->mChatInput,SIGNAL(sendChat(QString))
                ,this,SLOT(sendChat(QString)));
        connect(this->ui->mChatInput, SIGNAL(commandGiven(QString,QList<QString>)),
                this, SLOT(commandGiven(QString,QList<QString>)));


        connect(this->server, SIGNAL(connected()), this, SLOT(serverConnected()));
        connect(this->server, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));

        connect(this->server, SIGNAL(userQueryCompleted(QVector<ircUser*>)),
                this, SLOT(userQueryCompleted(QVector<ircUser*>)));

		connect(this->server, SIGNAL(userStatusChange(eventUserChangeStatus*)),
				this, SLOT(userStatusChange(eventUserChangeStatus*)));
		connect(this->server, SIGNAL(userLeave(eventUserLeave*)),
				this, SLOT(userLeave(eventUserLeave*)));
        connect(this->server, SIGNAL(userEnter(eventUserJoin*)),
                this, SLOT(userEnter(eventUserJoin*)));
		connect(this->server, SIGNAL(userChangeNick(eventUserChangeNick*)),
				this, SLOT(userChangeNick(eventUserChangeNick*)));

		connect(this->server, SIGNAL(serverMessageReceived(eventServerMessage*)),
				this, SLOT(serverMessageReceived(eventServerMessage*)));

		connect(this->server, SIGNAL(sgnConnectTimeout()), this, SLOT(connectedTimeout()));

		this->showMessage("Connecting to server",SERVERMESSAGE_LEVEL_INFO);
        this->server->doConnect();
    }


    MainWindow::~MainWindow()
    {
        delete this->server;
        delete ui;
    }

    void MainWindow::chatReceived(eventChat *chatEvent){
        this->ui->chatbox->addChat(this->users[chatEvent->getUser()],
                chatEvent->getMessage(), chatEvent->getTime());
    }

    void MainWindow::sendChat(QString message){
        jsonCommand toSend(JSONCOMMAND_OWNCHAT);
        toSend.addToData("chat",message);

        this->server->sendCommand(toSend);
    }

    void MainWindow::commandGiven(QString command, QList<QString> args){
        if(command == "status"){
            jsonCommand toSend(JSONCOMMAND_CHANGEOWNUSER);
            toSend.addToData("change","STATUS");
            if(args.length() == 0){
                //Set status online
                toSend.addToData("new","");
            }else{
                toSend.addToData("new",args[0]);
            }
            this->server->sendCommand(toSend);
        }
    }

    void MainWindow::moveScrollBarToBottom(int min, int max){
        Q_UNUSED(min);
        this->ui->scrollArea->verticalScrollBar()->setValue(max);
    }

    void MainWindow::serverConnected(){
		//this->ui->chatbox->addMessage("Connected!");
		this->showMessage("Connected to server",SERVERMESSAGE_LEVEL_INFO);
        //Do user query
        jsonCommand toSend(JSONCOMMAND_USERQUERY);
        this->server->sendCommand(toSend);
    }


    void MainWindow::serverDisconnected(){
		QString msg("Disconnected from server. Reconnecting in %1 seconds");
		msg = msg.arg(qint32(RECONNECT_IN_S));
		this->showMessage(msg,SERVERMESSAGE_LEVEL_ERROR);
		//Now, let's reconnect in RECONNECT_IN_S
		QTimer::singleShot(RECONNECT_IN_S*1000, this,
										SLOT(doReconnect()));
    }

    void MainWindow::userQueryCompleted(QVector<ircUser *> users){

#ifdef DESKTOP
		//this->ui->userList->clear();
		if(this->users.count() > 0){
			this->ui->userList = new clsUserList(this);
		}
#endif
		this->users.clear();
        foreach(ircUser* user, users){
#ifdef DESKTOP
            this->ui->userList->addUser(user);
#endif
            this->users.insert(user->getId(),user);
        }
        //Ask for events that happened in the last time..
        jsonCommand messageQuery(JSONCOMMAND_GETEVENTS);
        this->server->sendCommand(messageQuery);
    }

	void MainWindow::userStatusChange(eventUserChangeStatus *statusEvent){
		int userId = statusEvent->getUserId();
		this->users[userId]->setStatus(statusEvent->getNewStatus());
#ifdef DESKTOP
		this->ui->userList->refreshUser(this->users[userId]);
#endif
		this->ui->chatbox->addMessage(QString(this->users[userId]->getNick()) + " is nu " +
				this->users[userId]->getStatus());
    }

	void MainWindow::userChangeNick(eventUserChangeNick *nickEvent){
		int userId = nickEvent->getUserId();
		this->users[userId]->setNick(nickEvent->getNewNick());
#ifdef DESKTOP
		this->ui->userList->refreshUser(this->users[userId]);
#endif
		this->ui->chatbox->addMessage(nickEvent->getOldNick() + " is nu bekend als " +
				this->users[userId]->getNick());
    }

    void MainWindow::userLeave(eventUserLeave *leaveEvent){
        int userId = leaveEvent->getUserId();
        QString username = "";
        if(this->users.contains(userId)){
            if(this->users[userId]->getStandard()){
                this->users[userId]->setOnline(false);
                username = this->users[userId]->getNick();
#ifdef DESKTOP
                this->ui->userList->refreshUser(this->users[userId]);
#endif
            }else{
#ifdef DESKTOP
                this->ui->userList->removeUser(this->users[userId]);
#endif
                username = this->users[userId]->getNick();
                this->users.remove(userId);
            }
			this->ui->chatbox->addMessage(username + " is weggegaan",
										  leaveEvent->getTime());
        }
    }


    void MainWindow::userEnter(eventUserJoin *uEvent){
        ircUser *newUser = new ircUser(uEvent->getUser());
        QString username = newUser->getNick();

        if(newUser->getStandard() || this->users.keys().contains(newUser->getId())){
            //If it was already in there
            //It can only occur when bot has just started and the userquery also returns
            //a user that isn't standard
            this->users[newUser->getId()]->copyFrom(newUser);
#ifdef DESKTOP
            this->ui->userList->refreshUser(this->users[newUser->getId()]);
#endif
        }else{
            //Just add it
#ifdef DESKTOP
            this->ui->userList->addUser(newUser);
#endif
            this->users.insert(newUser->getId(),newUser);
        }
		this->ui->chatbox->addMessage(username + " is binnengekomen",
									  uEvent->getTime());
	}

	void MainWindow::serverMessageReceived(eventServerMessage *myMessage){
		//No more, no less
		QColor colorOfMessage;
		switch(myMessage->getLevel()){
			case SERVERMESSAGE_LEVEL_ERROR:
				colorOfMessage.setRgb(160,0,0);
				break;
			case SERVERMESSAGE_LEVEL_INFO:
				colorOfMessage.setRgb(0,160,0);
				break;
		}

		QString message(myMessage->getMessage());
		this->ui->chatbox->addMessage(message, myMessage->getTime(),
									  colorOfMessage);
	}

	void MainWindow::showMessage(QString msg, level lvl){
		QColor colorOfMessage;
		switch(lvl){
			case SERVERMESSAGE_LEVEL_ERROR:
				colorOfMessage.setRgb(160,0,0);
				break;
			case SERVERMESSAGE_LEVEL_INFO:
				colorOfMessage.setRgb(0,160,0);
				break;
		}
		this->ui->chatbox->addMessage(msg, QTime::currentTime(),
									  colorOfMessage);
	}

	void MainWindow::connectedTimeout(){
		QString msg("Unable to connect to server. Reconnecting in %1 seconds");
		msg = msg.arg(qint32(RECONNECT_IN_S));
		this->showMessage(msg,SERVERMESSAGE_LEVEL_ERROR);
		//Now, let's reconnect in RECONNECT_IN_S
		QTimer::singleShot(RECONNECT_IN_S*1000, this,
										SLOT(doReconnect()));
	}

	void MainWindow::doReconnect(){
		this->showMessage("Reconnecting",SERVERMESSAGE_LEVEL_INFO);
		this->server->doConnect();
	}


#ifdef ANDROID

    void MainWindow::setOrientation(ScreenOrientation orientation)
    {
        Qt::WidgetAttribute attribute;
        switch (orientation) {
#if QT_VERSION < 0x040702
            // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
            case ScreenOrientationLockPortrait:
                attribute = static_cast<Qt::WidgetAttribute>(128);
                break;
            case ScreenOrientationLockLandscape:
                attribute = static_cast<Qt::WidgetAttribute>(129);
                break;
            default:
            case ScreenOrientationAuto:
                attribute = static_cast<Qt::WidgetAttribute>(130);
                break;
#else // QT_VERSION < 0x040702
            case ScreenOrientationLockPortrait:
                attribute = Qt::WA_LockPortraitOrientation;
                break;
            case ScreenOrientationLockLandscape:
                attribute = Qt::WA_LockLandscapeOrientation;
                break;
            default:
            case ScreenOrientationAuto:
                attribute = Qt::WA_AutoOrientation;
                break;
#endif // QT_VERSION < 0x040702
        };
        setAttribute(attribute, true);
    }

    void MainWindow::showExpanded()
    {
#if defined(Q_WS_SIMULATOR)
        showFullScreen();
#elif defined(Q_WS_MAEMO_5)
        showMaximized();
#else
        show();
#endif
    }
#endif /* ANDROID */
}
