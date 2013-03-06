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
    void chatReceived(const QString channel, const QString user,
                      const QString message);
    void userOnline(const QString nick, const QString id);

    
private:
    const static logTags TAG = LOGTAGS_MAIN;
    ircClient *irc;
    ircUserList *users;
};

#endif // MAINAPP_H
