#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log(LOGTAGS_UI),
    server(new clsServerConn("home.k-4u.nl",1337))
{
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
    connect(this->server, SIGNAL(userLeave(int)),
            this, SLOT(userLeave(int)));
    connect(this->server, SIGNAL(userEnter(ircUser*)),
            this, SLOT(userEnter(ircUser*)));
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
        this->ui->userList->addUser(user);
        this->users.insert(user->getId(),user);
    }
    //Ask for events that happened in the last time..
    jsonCommand messageQuery(JSONCOMMAND_GETEVENTS);
    this->server->sendCommand(messageQuery);
}

void MainWindow::userStatusChange(int id, QString newStatus){
    this->users[id]->setStatus(newStatus);
    this->ui->userList->refreshUser(this->users[id]);
    this->ui->chatbox->addMessage(QString(this->users[id]->getNick()) + " is nu " +
                                  this->users[id]->getStatus());
}

void MainWindow::userChangeNick(int id, QString newNick){
    QString oldNick = this->users[id]->getNick();
    this->users[id]->setNick(newNick);
    this->ui->userList->refreshUser(this->users[id]);
    this->ui->chatbox->addMessage(oldNick + " is nu bekend als " +
                                  this->users[id]->getNick());
}

void MainWindow::userLeave(int userId){
    QString username = "";
    if(this->users[userId]->getStandard()){
        this->users[userId]->setOnline(false);
        username = this->users[userId]->getNick();
        this->ui->userList->refreshUser(this->users[userId]);
    }else{
        this->ui->userList->removeUser(this->users[userId]);
        username = this->users[userId]->getNick();
        this->users.remove(userId);
    }
    this->ui->chatbox->addMessage(username + " is weggegaan");
}


void MainWindow::userEnter(ircUser *newUser){
    QString username = newUser->getNick();;
    if(newUser->getStandard()){
        this->users[newUser->getId()]->copyFrom(newUser);
        this->ui->userList->refreshUser(this->users[newUser->getId()]);
    }else{
        //Just add it
        this->ui->userList->addUser(newUser);
        this->users.insert(newUser->getId(),newUser);
    }
    this->ui->chatbox->addMessage(username + " is binnengekomen");
}
