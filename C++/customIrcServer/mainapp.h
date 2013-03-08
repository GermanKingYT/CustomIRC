#ifndef MAINAPP_H
#define MAINAPP_H

#include <QObject>
#include <QVector>
#include "ircclient.h"
#include "functions.h"
#include "ircuser.h"


class mainApp : public QObject
{
    Q_OBJECT
public:
    explicit mainApp(QObject *parent = 0);
    void run();


signals:
    
public slots:
    void chatReceived(const QString channel, const nickAndStatus user,
                      const QString message);
    void userOnline(const nickAndStatus nick, const QString id,
                    const QString channel);
    void userOffline(const nickAndStatus nick, const QString id,
                     const QString channel);

    void userChangeNick(const nickAndStatus oldNickName,
                        const nickAndStatus newNickName,
                        const QString id);
    void userChangeStatus(const nickAndStatus oldNick,
                          const nickAndStatus newNick,
                          const QString id);

    
private:
    const static logTags TAG = LOGTAGS_MAIN;
    ircClient *irc;
    ircUserList *users;
    clsLog log;
};

#endif // MAINAPP_H
