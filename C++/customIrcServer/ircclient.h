#ifndef IRCCLIENT_H
#define IRCCLIENT_H

#include <QVector>
#include <QBuffer>
#include <QString>
#include <QTcpSocket>
#include <QStringList>
#include <QTextStream>
#include "ircCodes.h"
#include "functions.h"
#include "clslog.h"



#define CHANNEL "bottest"
#define NICK    "KoeBot"
class ircClient : public QObject{
    Q_OBJECT

public:
    ircClient(const char *hostname, const int port, const char *channel,
              const char *nick);
    ircClient(const char *hostname, const char *channel);
    ircClient(const char *hostname, const char *channel, const char *nick);
    ircClient(const char *hostname, const int port);
    ircClient(const char *hostname);
    ~ircClient();

    void connect();

    void sendChat(const char *msg, const char *channel);
    void sendChat(const char *msg);
    void sendChat(const QString &msg);

    nickAndStatus getOwnNick() const;

signals:
    void startupComplete();
    void chatReceived(const QString channel, const nickAndStatus user,
                      const QString message);
    void userOnline(const nickAndStatus nickName, const QString id,
                    const QString channel);
    void userOffline(const nickAndStatus nickName, const QString id,
                     const QString channel);
    void userChangeNick(const nickAndStatus oldNickName,
                        const nickAndStatus newNickName,
                        const QString id);
    void userChangeStatus(const nickAndStatus oldNick,
                          const nickAndStatus newNick,
                          const QString id);


private:
    void init();
    void send(const QString data);
    void send(const char *data);
    void handleCommand(const QString &sender, const QStringList &command);
    void sendPong(const QString packet);

public slots:
    void disconnected();
    void connected();
    void readData();

private:
    QString hostname;
    int port;
    QString channel;
    bool motdReceived;

    QTcpSocket *sock;
    QBuffer *buffer;

    clsLog log;

    nickAndStatus ownNickAndStatus;


    const static int PORT = 6667;
};

#endif // IRCCLIENT_H
