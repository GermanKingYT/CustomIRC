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


        /*connect(this->server,SIGNAL(chatReceived(int,QString, QTime))
          ,this,SLOT(chatReceived(int,QString, QTime)));*/
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

        connect(this->server, SIGNAL(userStatusChange(int,QString)),
                this, SLOT(userStatusChange(int,QString)));
        //connect(this->server, SIGNAL(userLeave(eventUserLeave*)),
        //        this, SLOT(userLeave(eventUserLeave*)));
        connect(this->server, SIGNAL(userEnter(eventUserJoin*)),
                this, SLOT(userEnter(eventUserJoin*)));
        connect(this->server, SIGNAL(userChangeNick(int,QString)),
                this, SLOT(userChangeNick(int,QString)));
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

    /*void MainWindow::chatReceived(int userId, QString message, QTime timeOfMessage){
      this->ui->chatbox->addChat(this->users[userId],message,timeOfMessage);
      }*/

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
        this->ui->chatbox->addMessage("Connected!");
        //Do user query
        jsonCommand toSend(JSONCOMMAND_USERQUERY);
        this->server->sendCommand(toSend);
    }


    void MainWindow::serverDisconnected(){
        this->ui->chatbox->addMessage("Disconnect from server!");
    }

    void MainWindow::userQueryCompleted(QVector<ircUser *> users){
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

    void MainWindow::userStatusChange(int id, QString newStatus){
        this->users[id]->setStatus(newStatus);
#ifdef DESKTOP
        this->ui->userList->refreshUser(this->users[id]);
#endif
        this->ui->chatbox->addMessage(QString(this->users[id]->getNick()) + " is nu " +
                this->users[id]->getStatus());
    }

    void MainWindow::userChangeNick(int id, QString newNick){
        QString oldNick = this->users[id]->getNick();
        this->users[id]->setNick(newNick);
#ifdef DESKTOP
        this->ui->userList->refreshUser(this->users[id]);
#endif
        this->ui->chatbox->addMessage(oldNick + " is nu bekend als " +
                this->users[id]->getNick());
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
            this->ui->chatbox->addMessage(username + " is weggegaan");
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
        this->ui->chatbox->addMessage(username + " is binnengekomen");
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
