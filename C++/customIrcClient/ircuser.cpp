#include "ircuser.h"

ircUser::ircUser(QVariant jsonData)
    :log(LOGTAGS_USER)
{
    QVariantMap data = jsonData.toMap();
    this->id = data["id"].toInt();
    this->nick = data["nick"].toString();
    this->status = data["status"].toString();
    this->standard = data["standard"].toBool();
    this->uColor = QColor(data["uColor"].toMap()["r"].toInt(),
            data["uColor"].toMap()["g"].toInt(),
            data["uColor"].toMap()["b"].toInt());

}

ircUser::ircUser(qint32 id, QString nick, QString status, QColor uColor, bool standard)
    :id(id)
    ,nick(nick)
    ,status(status)
    ,uColor(uColor)
    ,standard(standard)
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

const QColor ircUser::getColor() const{
    return this->uColor;
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
