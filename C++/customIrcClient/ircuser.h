#ifndef IRCUSER_H
#define IRCUSER_H

#include <QString>
#include <QColor>
#include "clslog.h"

class ircUser
{
public:
    ircUser(qint32 id, QString nick, QString status, QColor uColor);

    //Getters
    const QString getNick() const;
    qint32 getId() const;
    const QString getStatus() const;
    const QColor getColor() const;

    //Setters
    void setNick(const QString &newNick); //Probably never used
    void setStatus(const QString &newStatus);
    void setColor(const QColor &newColor); //Also probably never used

private:
    qint32 id;
    QString nick;
    QString status;
    QColor uColor;

    clsLog log;
};

#endif // IRCUSER_H
