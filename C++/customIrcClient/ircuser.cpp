#include "ircuser.h"

ircUser::ircUser(qint32 id, QString nick, QString status, QColor uColor)
    :id(id)
    ,nick(nick)
    ,status(status)
    ,uColor(uColor)
    ,log(LOGTAGS_USER)
{}

const QString ircUser::getNick() const{
    return this->nick;
}


qint32 ircUser::getId() const{
    return this->id;
}

const QString ircUser::getStatus() const{
    return this->status;
}


void ircUser::setNick(const QString &newNick){
    this->nick = newNick;
}

void ircUser::setStatus(const QString &newStatus){
    this->status = newStatus;
}

void ircUser::setColor(const QColor &newColor){
    this->uColor = newColor;
}
