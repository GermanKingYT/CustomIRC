#include "ircuser.h"
#include <QCryptographicHash>

namespace client{

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
        this->online = data["online"].toBool();
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

    void ircUser::copyFrom(ircUser *userToCopy){
        this->nick = userToCopy->nick;
        this->status = userToCopy->status;
        this->uColor = userToCopy->uColor;
        this->online = userToCopy->online;
    }

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

    bool ircUser::getStandard() const{
        return this->standard;
    }

    bool ircUser::getOnline() const{
        return this->online;
    }

    void ircUser::setNick(const QString &newNick){
        this->nick = newNick;
    }

    void ircUser::setStatus(const QString &newStatus){
        if(newStatus == ""){
            this->status = "Online";
        }else{
            this->status = newStatus;
        }
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


    void ircUser::setOnline(const bool isOnline){
        this->online = isOnline;
        if(this->online == false){
            this->status = "Offline";
        }
    }

}
