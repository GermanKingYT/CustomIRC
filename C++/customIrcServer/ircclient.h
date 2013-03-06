#ifndef IRCCLIENT_H
#define IRCCLIENT_H

#include <QThread>
#include <QString>
#include <QTcpSocket>
#include "functions.h"

class ircClient : public QObject
{
    Q_OBJECT

public:
    ircClient(const char *hostname, const int port);
    ircClient(const char *hostname);
    ~ircClient();

    void connect();

private:
    void init();

public slots:
    void disconnected();
    void connected();
    void readData();

private:
    QString hostname;
    QString nick;
    int port;



    QTcpSocket *sock;


    //CONFIG
    const static logTags TAG = LOGTAGS_IRC;
    const static int PORT = 6667;
};

#endif // IRCCLIENT_H
