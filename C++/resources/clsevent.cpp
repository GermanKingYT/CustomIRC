#include "clsevent.h"

clsEvent::clsEvent(){
    this->timeOfEvent = QDateTime::currentDateTime();
}

clsEvent::clsEvent(QVariantMap data){
    this->data = data["data"].toMap();//Makes sense?
    this->setEventType(data["type"].toString());
    this->timeOfEvent = data["dateTime"].toDateTime();
}

void clsEvent::addToData(const QString &key, const QVariant data){
    this->data.insert(key, data);
}

QVariant clsEvent::toVariant() const{
    QVariantMap ret;
    ret["type"] = this->getEventType();
    ret["dateTime"] = this->timeOfEvent;
    ret["data"] = QVariant(this->data);

    return QVariant(ret);
}

QVariant clsEvent::getData(QString key) const{
    return this->data[key];
}

void clsEvent::setEventType(const QString eventString){
    eventTypes ret = EVENTTYPE_NONE;
    if(eventString == "CHAT"){
        ret = EVENTTYPE_CHAT;
    }

    this->ourType = ret;
}

QString clsEvent::getEventType() const{
    QString ret = "";
    switch(this->ourType){
        case EVENTTYPE_CHAT:
            ret = "CHAT";
            break;
        case EVENTTYPE_NONE:
            ret = "NaN";
            break;
    }
    return ret;
}


eventChat::eventChat(int userId, QString message){
    ourType = EVENTTYPE_CHAT;
    this->addToData("user",userId);
    this->addToData("message", message);
}

eventChat::eventChat(QVariantMap data){
    QVariantMap d = data;
    this->data = data["data"].toMap();//Makes sense?
    this->setEventType(data["type"].toString());
    this->timeOfEvent = data["dateTime"].toDateTime();
}

int eventChat::getUser() const{
    return this->getData("user").toInt();
}

QString eventChat::getMessage() const{
    return this->getData("message").toString();
}

QTime eventChat::getTime() const{
    return this->timeOfEvent.time();
}