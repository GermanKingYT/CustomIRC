#ifndef CLSEVENT_H
#define CLSEVENT_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDateTime>

enum eventTypes{
    EVENTTYPE_NONE = 0x00,
    EVENTTYPE_CHAT,
    EVENTTYPE_USER_LEFT,
    EVENTTYPE_USER_STATUS,
    EVENTTYPE_USER_JOIN
};


class clsEvent
{
public:
    explicit clsEvent();
    explicit clsEvent(QVariantMap data);
    void addToData(const QString &key, const QVariant data);

    QVariant toVariant() const;

    QVariant getData(QString key) const;

    eventTypes getType() const;
protected:
    QVariantMap data;
    eventTypes ourType;
    QDateTime timeOfEvent;
    QString getEventType() const;
    void setEventType(const QString eventString);
};

class eventChat : public clsEvent
{
public:
    eventChat(int userId, QString message);
    eventChat(QVariantMap data);

    int getUser() const;
    QString getMessage() const;
    QTime getTime() const;
};

class eventUserJoin : public clsEvent
{
public:
    eventUserJoin(const int userId, QVariantMap user);
    eventUserJoin(QVariantMap data);

    int getUserId() const;
    QVariantMap getUser();
    QTime getTime() const;

};
#endif // CLSEVENT_H
