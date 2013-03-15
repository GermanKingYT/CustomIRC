#ifndef UICLIENT_H
#define UICLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QBuffer>

#include "clslog.h"
#include "jsoncommand.h"
#include "json.h"


class uiClient: public QObject{
    Q_OBJECT
public:
    uiClient(QTcpSocket *parent);
    
signals:
    void disconnected(uiClient *client);
public slots:
    void removeConnection();
    void receiveMessage();

private:
    QTcpSocket *sock;
    clsLog log;
    QBuffer *buffer;
};

#endif // UICLIENT_H
