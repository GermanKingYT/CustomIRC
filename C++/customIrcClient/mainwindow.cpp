#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log(LOGTAGS_UI),
    server(new clsServerConn("localhost",1337))
{
    ui->setupUi(this);

    connect(this->ui->scrollArea->verticalScrollBar(),SIGNAL(rangeChanged(int,int)),
            this,SLOT(moveScrollBarToBottom(int,int)));


    connect(this->server,SIGNAL(chatReceived(ircUser*,QString))
            ,this,SLOT(chatReceived(ircUser*,QString)));
    connect(this->ui->mChatInput,SIGNAL(sendChat(QString))
            ,this,SLOT(sendChat(QString)));
    connect(this->server, SIGNAL(connected()), this, SLOT(serverConnected()));
    connect(this->server, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));

    connect(this->server, SIGNAL(userQueryCompleted(QVector<ircUser*>)),
            this, SLOT(userQueryCompleted(QVector<ircUser*>)));
    this->server->doConnect();
}


MainWindow::~MainWindow()
{
    delete this->server;
    delete ui;
}

void MainWindow::chatReceived(ircUser *user, QString message){
    this->ui->chatbox->addChat(user,message);
}

void MainWindow::sendChat(QString message){
    jsonCommand toSend(JSONCOMMAND_OWNCHAT);
    toSend.addToData("chat",message);

    this->server->sendCommand(toSend);
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
    foreach(ircUser* user, users){
        this->ui->userList->addUser(user);
    }
}
