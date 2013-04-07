#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QScrollArea>
#include <QScrollBar>
#include "../resources/clslog.h"
#include "../resources/clsevent.h"
#include "chatbox.h"
#include "clsserverconn.h"
#include "clssettings.h"

#ifdef DESKTOP
#include "clsnotify.h"
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QApplication *a, QWidget *parent = 0);
    ~MainWindow();
    
#ifdef ANDROID
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };
    // Note that this will only have an effect on Fremantle.
    void setOrientation(ScreenOrientation orientation);
    void showExpanded();
#endif


private slots:
    void chatReceived(eventChat *chatEvent);
    //void chatReceived(int userId, QString message, QTime timeOfMessage);
    void sendChat(QString message);
    void commandGiven(QString command, QList<QString> args);
    void moveScrollBarToBottom(int min, int max);


    void serverConnected();
    void serverDisconnected();
    void userQueryCompleted(QVector<ircUser*> users);
    void userStatusChange(int id, QString newStatus);
    void userChangeNick(int id, QString newNick);
    void userLeave(int userId);
    void userEnter(ircUser *newUser);

private:
    Ui::MainWindow *ui;

    clsLog log;
    chatBox *cb;

    clsServerConn *server;

    QMap<int, ircUser *> users;

    clsSettings *settings;
};

#endif // MAINWINDOW_H
