#ifndef SIMPLECHATSERVER_H
#define SIMPLECHATSERVER_H

#include <QTcpServer>
#include <QList>
#include <QHash>
#include "uiclient.h"
#include "clslog.h"

class QBuffer;
class QTcpSocket;

class uiServer : public QTcpServer
{
	Q_OBJECT

public:
    uiServer(QObject* parent = 0);
    ~uiServer();

    void startListen();
private slots:
    void acceptConnection();
    void lostConnection(uiClient* client);


private:
    QList<uiClient*> connections;

    clsLog log;

    static const int port = 1337;
};

#endif // SIMPLECHATSERVER_H
