#ifndef CLSSETTINGS_H
#define CLSSETTINGS_H

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QVector>
#include "ircuser.h"


class clsSettings
{
public:
    clsSettings(const QString &fileName);


    QString getServer() const;
    QString getChannel() const;
    QString getUserName() const;

    ircUser *getOwnUser() const;

    QVector<ircUser *> getUsers() const;
private: //Functions
    void readServer(QXmlStreamReader &reader);
    void readUsers(QXmlStreamReader &reader);
    void readUserInfo(QXmlStreamReader &reader);


private: //Values
    QString server;
    QString channel;
    ircUser *ownUser;

    QVector<ircUser*> users;

};

#endif // CLSSETTINGS_H
