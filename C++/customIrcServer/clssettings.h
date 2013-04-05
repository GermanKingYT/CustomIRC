#ifndef CLSSETTINGS_H
#define CLSSETTINGS_H

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QVector>
#include "ircuser.h"

#define DEFAULT_LISTEN_PORT 1337

class clsSettings
{
public:
    clsSettings(const QString &filePath);


    int getListeningPort() const;
    QString getServer() const;
    QString getChannel() const;
    QString getUserName() const;

    ircUser *getOwnUser() const;

    QVector<ircUser *> getUsers() const;
private: //Functions
    void readUiSettings(QXmlStreamReader &reader);
    void readServer(QXmlStreamReader &reader);
    void readUsers(QXmlStreamReader &reader);
    void readUserInfo(QXmlStreamReader &reader);


private: //Values
    QString server;
    QString channel;
    ircUser *ownUser;
    int listeningPort;

    QVector<ircUser*> users;

};

#endif // CLSSETTINGS_H
