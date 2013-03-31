#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QScrollArea>
#include <QScrollBar>
#include "../resources/clslog.h"
#include "chatbox.h"
#include "clsserverconn.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

private slots:
    void chatReceived(ircUser *user, QString message);
    void sendChat(QString message);
    void moveScrollBarToBottom(int min, int max);


    void serverConnected();
    void serverDisconnected();
    void userQueryCompleted(QVector<ircUser*> users);
private:
    Ui::MainWindow *ui;

    clsLog log;
    chatBox *cb;

    clsServerConn *server;
};

#endif // MAINWINDOW_H
