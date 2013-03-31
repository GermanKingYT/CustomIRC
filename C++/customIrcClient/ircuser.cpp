#include "ircuser.h"
#include <QCryptographicHash>

ircUser::~ircUser(){
}


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
    this->email = data["email"].toString();
    //Fetch gravatar here plox
    //Fetch gravatar
    QNetworkAccessManager *m_netwManager = new QNetworkAccessManager();
    connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(slot_netwManagerFinished(QNetworkReply*)));

    QString hash = QString(
                QCryptographicHash::hash(this->email.trimmed().toLower().toUtf8(),
                                         QCryptographicHash::Md5).toHex());
    QUrl url("http://www.gravatar.com/avatar/" + hash);
    QNetworkRequest request(url);
    m_netwManager->get(request);
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

const QPixmap ircUser::getIcon() const{
    return this->icon;
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


void ircUser::slot_netwManagerFinished(QNetworkReply *reply){
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }

    QByteArray jpegData = reply->readAll();
    this->icon.loadFromData(jpegData);
    //this->ui->lblGravatar->setPixmap(pixmap.scaled(this->ui->lblGravatar->size()));
    emit this->iconChanged();
}

