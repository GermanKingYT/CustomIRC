#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    log(LOGTAGS_UI),
    server(new clsServerConn("localhost",1337))
{
    ui->setupUi(this);
    this->server->doConnect();
}


MainWindow::~MainWindow()
{
    delete this->server;
    delete ui;
}
