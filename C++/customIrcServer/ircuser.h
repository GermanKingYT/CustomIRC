#ifndef IRCUSER_H
#define IRCUSER_H

#include <QString>
#include <QVector>
#include <QVariantMap>
#include "functions.h"
#include "../resources/clslog.h"

class ircUser {


public:
    struct userColor{
        int r;
        int g;
        int b;
    };
    ircUser(const nickAndStatus name, const QString ircId);
    ircUser(const nickAndStatus name, const bool standard);
    ircUser(const QString name, const bool standard);
    ircUser(const QString name, const bool standard, const userColor color);
    ircUser(const nickAndStatus name);

    ircUser();

    //Getters
    QString getName() const;
    bool getOnline() const;
    QString getStatus() const;
    bool isStandard() const;
    QVariantMap toVariantMap() const;
    QString getIrcId() const;
    int getId() const;

    //Setters
    void setOnline(const bool isOnline);
    void setStatus(const QString &newStatus);
    void setIrcId(const QString &newId);
    void setId(const int &newId);
    void setNick(const QString &newNick);
    void setColor(const int r, const int g, const int b);
    void setColor(const userColor &newColor);
    void setEmail(const QString &email);


    friend clsLog& operator<<(clsLog& log, const ircUser* user);

private:
    QString name;
    QString ircId;
    int id;
    QString status;
    QString email;
    bool online;
    bool standard;

    userColor uColor;

    clsLog log;
};

class ircUserList {
public:
    ircUserList();

    void add(ircUser *userToAdd);
    void del(ircUser *userToDel);

    ircUser *getUserByNick(nickAndStatus nick);
    ircUser *getUser(const nickAndStatus nick, const QString ircId);
    ircUser *findUser(ircUser &userToFind);
    ircUser *getUserById(int id);
    ircUser *getUserByIrcId(QString ircId);
    QVector<ircUser*> getAll() const;


private:
    QVector<ircUser*> users;
    int lastId;
};
#endif // IRCUSER_H
