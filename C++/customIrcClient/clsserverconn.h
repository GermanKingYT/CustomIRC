#ifndef CLSSERVERCONN_H
#define CLSSERVERCONN_H

#include <QObject>
#include <QTcpSocket>
#include <QTextStream>
#include "clslog.h"
#include <QBuffer>
#include "ircuser.h"
#include "jsoncommand.h"
#include "json.h"


class clsServerConn : public QObject
{
    Q_OBJECT
public:
    explicit clsServerConn(const QString hostName, const int port,
                           QObject *parent = 0);
    
    void doConnect();
    void sendCommand(jsonCommand &toSend);

signals:
    void chatReceived(ircUser user, QString message);

    
public slots:
    void disconnected();
    void connected();
    void readData();



private:
    QString hostName;
    int port;

    QTcpSocket *sock;
    QBuffer *buffer;

    clsLog log;

    
};

#endif // CLSSERVERCONN_H
