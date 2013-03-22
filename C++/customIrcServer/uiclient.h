#ifndef UICLIENT_H
#define UICLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QBuffer>
#include <QJsonDocument>

#include "clslog.h"
#include "jsoncommand.h"


class uiClient: public QObject{
    Q_OBJECT
public:
    uiClient(QTcpSocket *parent);
    
    void send(QString data);
signals:
    void disconnected(uiClient *client);
    void chatReceived(QString message);

public slots:
    void removeConnection();
    void receiveMessage();

private:
    QTcpSocket *sock;
    clsLog log;
    QBuffer *buffer;
};

#endif // UICLIENT_H
