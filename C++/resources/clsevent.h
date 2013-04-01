#ifndef CLSEVENT_H
#define CLSEVENT_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDateTime>

enum eventTypes{
    EVENTTYPE_NONE = 0x00,
    EVENTTYPE_CHAT
};

class clsEvent : public QObject
{
    Q_OBJECT
public:
    explicit clsEvent();
    explicit clsEvent(QVariantMap data);
    void addToData(const QString &key, const QVariant data);

    QVariant toVariant() const;

    QVariant getData(QString key) const;

protected:
    QVariantMap data;
    eventTypes ourType;
    QDateTime timeOfEvent;
    QString getEventType() const;
    void setEventType(const QString eventString);

signals:
    
public slots:
    
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


#endif // CLSEVENT_H
