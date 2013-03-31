#ifndef CLSSERVERCONN_H
#define CLSSERVERCONN_H

#include <QObject>
#include <QTcpSocket>
#include <QTextStream>
#include "../resources/clslog.h"
#include <QBuffer>
#include "ircuser.h"
#include "../resources/jsoncommand.h"
#include "../resources/json.h"


class clsServerConn : public QObject
{
    Q_OBJECT
public:
    explicit clsServerConn(const QString hostName, const int port,
                           QObject *parent = 0);
    
    void doConnect();
    void sendCommand(jsonCommand &toSend);

    void handleCompletedQuery(jsonCommand *comm);
signals:
    void chatReceived(ircUser *user, QString message);
    void connected();
    void disconnected();
    void userQueryCompleted(QVector<ircUser*> users);

public slots:
    void srvDisconnected();
    void srvConnected();
    void readData();



private:
    QString hostName;
    int port;

    QTcpSocket *sock;
    QBuffer *buffer;

    clsLog log;

    
};

#endif // CLSSERVERCONN_H
