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



#define CHANNEL "mattiechat"
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


signals:
    void startupComplete();
    void chatReceived(const QString channel, const QString user,
                      const QString message);
    void userOnline(const QString nickName, const QString id);
    void userOffline(const QString nickName, const QString id);
    void userChangeNick(const QString oldNickName, const QString newNickName,
                          const QString id);

private:
    void init();
    void send(const QString data);
    void send(const char *data);
    void handleCommand(const QString &sender, const QStringList &command);
    void sendPong(const QString packet);

    const QString getNicKFromId(const QString id);

public slots:
    void disconnected();
    void connected();
    void readData();

private:
    QString hostname;
    QString nick;
    int port;
    QString channel;
    bool motdReceived;

    QTcpSocket *sock;
    QBuffer *buffer;

    clsLog log;

    const static int PORT = 6667;
};

#endif // IRCCLIENT_H
