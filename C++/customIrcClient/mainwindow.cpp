#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log(LOGTAGS_UI),
    server(new clsServerConn("localhost",1337))
{
    ui->setupUi(this);

    connect(this->server,SIGNAL(chatReceived(ircUser,QString))
            ,this,SLOT(chatReceived(ircUser,QString)));
    connect(this->ui->mChatInput,SIGNAL(sendChat(QString))
            ,this,SLOT(sendChat(QString)));
    this->server->doConnect();
}


MainWindow::~MainWindow()
{
    delete this->server;
    delete ui;
}

void MainWindow::chatReceived(ircUser user, QString message){
    this->ui->chatbox->addChat(user,message);
}

void MainWindow::sendChat(QString message){
    jsonCommand toSend(JSONCOMMAND_OWNCHAT);
    toSend.addToData("chat",message);

    this->server->sendCommand(toSend);
}
