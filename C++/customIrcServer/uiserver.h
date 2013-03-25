#ifndef SIMPLECHATSERVER_H
#define SIMPLECHATSERVER_H

#include <QTcpServer>
#include <QList>
#include <QHash>
#include "uiclient.h"
#include "../resources/clslog.h"
#include "../resources/jsoncommand.h"

class QBuffer;
class QTcpSocket;

class uiServer : public QTcpServer
{
	Q_OBJECT

public:
    uiServer(QObject* parent = 0);
    ~uiServer();

    void startListen();


    void send(jsonCommand &toSend);

private slots:
    void acceptConnection();
    void lostConnection(uiClient* client);

    void chatReceived(QString message);


signals:
    void sgnChatReceived(QString message);

private:
    QList<uiClient*> connections;

    clsLog log;

    static const int port = 1337;
};

#endif // SIMPLECHATSERVER_H
