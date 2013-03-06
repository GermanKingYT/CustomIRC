#ifndef IRCUSER_H
#define IRCUSER_H

#include <QString>
#include <QVector>
#include "functions.h"


class ircUser {
public:
    ircUser(const QString name, const QString id);
    ircUser(const QString name, const bool standard);
    ircUser(const QString name);
    ircUser();

    //Getters
    QString getName() const;
    bool getOnline() const;
    QString getStatus() const;

    //Setters
    void setOnline(const bool isOnline);
    void setStatus(const QString &newStatus);
    void setId(const QString *newId);

    QString getId() const;
private:
    QString name;
    QString id;
    QString status;
    bool online;
    bool standard;
};

class ircUserList {
public:
    ircUserList();

    void add(ircUser *userToAdd);


    ircUser *getUserByNick(QString nick);
    ircUser *getUser(const QString nick, const QString id);
    ircUser *findUser(ircUser &userToFind);
    ircUser *getUserById(QString id);
    QVector<ircUser> getAll() const;
private:
    QVector<ircUser> users;
};
#endif // IRCUSER_H
