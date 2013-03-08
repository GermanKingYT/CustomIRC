#ifndef IRCUSER_H
#define IRCUSER_H

#include <QString>
#include <QVector>
#include "functions.h"
#include "clslog.h"

class ircUser {
public:
    ircUser(const nickAndStatus name, const QString id);
    ircUser(const nickAndStatus name, const bool standard);
    ircUser(const QString name, const bool standard);
    ircUser(const nickAndStatus name);

    ircUser();

    //Getters
    QString getName() const;
    bool getOnline() const;
    QString getStatus() const;
    bool isStandard() const;

    //Setters
    void setOnline(const bool isOnline);
    void setStatus(const QString &newStatus);
    void setId(const QString &newId);
    void setNick(const QString &newNick);

    QString getId() const;
    friend clsLog& operator<<(clsLog& log, const ircUser* user);


private:
    QString name;
    QString id;
    QString status;
    bool online;
    bool standard;

    clsLog log;
};


class ircUserList {
public:
    ircUserList();

    void add(ircUser *userToAdd);
    void del(ircUser *userToDel);


    ircUser *getUserByNick(nickAndStatus nick);
    ircUser *getUser(const nickAndStatus nick, const QString id);
    ircUser *findUser(ircUser &userToFind);
    ircUser *getUserById(QString id);
    QVector<ircUser> getAll() const;

private:
    QVector<ircUser> users;
};
#endif // IRCUSER_H
