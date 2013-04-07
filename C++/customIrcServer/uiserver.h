#ifndef SIMPLECHATSERVER_H
#define SIMPLECHATSERVER_H

#include <QTcpServer>
#include <QList>
#include <QHash>
#include "uiclient.h"
#include "../resources/clslog.h"
#include "../resources/jsoncommand.h"

#define DEFAULT_LISTENING_PORT 1337

class QBuffer;
class QTcpSocket;

class uiServer : public QTcpServer
{
	Q_OBJECT

public:
    uiServer(int port = DEFAULT_LISTENING_PORT, QObject* parent = 0);
    ~uiServer();

    void startListen();


    void send(const jsonCommand &toSend);
    void send(uiClient *client, const jsonCommand &toSend);

private slots:
    void acceptConnection();
    void lostConnection(uiClient* client);

    void chatReceived(QString message);

    void doUserQuery(uiClient *client);
    void doSendEvents(uiClient *client);

    void changeOwnUser(jsonCommand &comm);
signals:
    void sgnChatReceived(QString message);
    void sgnUserQuery(uiClient *client);
    void sgnSendEvents(uiClient *client);
    void sgnChangeOwnUserStatus(QString newStatus);


private:
    QList<uiClient*> connections;

    clsLog log;

    int port;
};

#endif // SIMPLECHATSERVER_H
