#include "ircuser.h"

ircUser::ircUser(const nickAndStatus name, const QString id)
    :name(name.nick)
    ,id(id)
    ,status(name.status)
    ,online(true)
    ,log(LOGTAGS_USER)
{
    if(this->name.left(1) == ":"){
        this->name = this->name.mid(1);
    }
    this->online = false;
    if(this->name.indexOf("|") >= 0){
        this->status = this->name.mid(this->name.indexOf("|")+1);
        this->name = this->name.left(this->name.indexOf("|"));
    }
    this->uColor.r = 0;
    this->uColor.g = 0;
    this->uColor.b = 0;
}


ircUser::ircUser(const nickAndStatus name, const bool standard)
    :name(name.nick)
    ,id("NaN")
    ,status("Offline")
    ,online(false)
    ,standard(standard)
    ,log(LOGTAGS_USER)
{
    if(this->name.left(1) == ":"){
        this->name = this->name.mid(1);
    }
    if(!standard){
        this->online = true;
        this->status = "";
    }

    if(this->name.indexOf("|") >= 0){
        this->status = this->name.mid(this->name.indexOf("|")+1);
        this->name = this->name.left(this->name.indexOf("|"));
    }
    this->uColor.r = 0;
    this->uColor.g = 0;
    this->uColor.b = 0;
}

ircUser::ircUser(const nickAndStatus name)
    :name(name.nick)
    ,id("NaN")
    ,status(name.status)
    ,online(true)
    ,log(LOGTAGS_USER)
{
    if(this->name.left(1) == ":"){
        this->name = this->name.mid(1);
    }
    this->online = false;
    if(this->name.indexOf("|") >= 0){
        this->status = this->name.mid(this->name.indexOf("|")+1);
        this->name = this->name.left(this->name.indexOf("|"));
    }
    this->uColor.r = 0;
    this->uColor.g = 0;
    this->uColor.b = 0;
}

ircUser::ircUser(const QString name, const bool standard)
    :name(name)
    ,id("NaN")
    ,status("Offline")
    ,online(false)
    ,standard(standard)
    ,log(LOGTAGS_USER)
{
    if(this->name.left(1) == ":"){
        this->name = this->name.mid(1);
    }
    if(!standard){
        this->online = true;
        this->status = "";
    }

    if(this->name.indexOf("|") >= 0){
        this->status = this->name.mid(this->name.indexOf("|")+1);
        this->name = this->name.left(this->name.indexOf("|"));
    }

    this->uColor.r = 0;
    this->uColor.g = 0;
    this->uColor.b = 0;
}

ircUser::ircUser(const QString name, const bool standard, const ircUser::userColor color)
  :name(name)
  ,id("NaN")
  ,status("Offline")
  ,online(false)
  ,standard(standard)
  ,uColor(color)
  ,log(LOGTAGS_USER)
{
  this->log << name << endl;
  if(this->name.left(1) == ":"){
      this->name = this->name.mid(1);
  }
  if(!standard){
      this->online = true;
      this->status = "";
  }

  if(this->name.indexOf("|") >= 0){
      this->status = this->name.mid(this->name.indexOf("|")+1);
      this->name = this->name.left(this->name.indexOf("|"));
  }
}

ircUser::ircUser()
    :name("NaN")
    ,id("NaN")
    ,status("Offline")
    ,online(false)
    ,log(LOGTAGS_USER)
{
    this->uColor.r = 0;
    this->uColor.g = 0;
    this->uColor.b = 0;
}

QString ircUser::getName() const{
    return this->name;
}

QString ircUser::getStatus() const{
    return this->status;
}

bool ircUser::isStandard() const{
    return this->standard;
}

QVariantMap ircUser::toVariantMap() const{
    QVariantMap ret;
    QVariantMap color;
    color["r"] = this->uColor.r;
    color["g"] = this->uColor.g;
    color["b"] = this->uColor.b;

    ret["uColor"] = QVariant(color);
    ret["nick"] = this->name;
    ret["id"] = this->id; //Will be replaced by a number
    ret["status"] = this->status;
    ret["standard"] = this->standard;
    ret["isOnline"] = this->online;

    return ret;

}

void ircUser::setOnline(const bool isOnline){
    this->online = isOnline;
}

bool ircUser::getOnline() const{
    return this->online;
}

void ircUser::setStatus(const QString &newStatus){
    this->status = newStatus;
}

void ircUser::setId(const QString &newId){
    this->id = newId;
}

void ircUser::setNick(const QString &newNick){
    this->name = newNick;
}

void ircUser::setColor(const int r, const int g, const int b){
    this->uColor.r = r;
    this->uColor.g = g;
    this->uColor.b = b;
}

void ircUser::setColor(const ircUser::userColor &newColor){
    this->uColor = newColor;
}


QString ircUser::getId() const{
    return this->id;
}

clsLog &operator <<(clsLog &log, const ircUser *user){
    log << "USER: name: \t" << user->name << "\tStatus:\t" << user->status;
    log << "\tStandard: \t" << user->standard << endl;
    return log;
}


ircUserList::ircUserList(){
}

ircUser::userColor getColor(int length){
    ircUser::userColor retColor;
    switch(length){
        case 0:
            retColor.r = 160;
            retColor.g = 25;
            retColor.b = 25;
            break;
        case 1:
            retColor.r = 25;
            retColor.g = 25;
            retColor.b = 160;
            break;
        case 2:
            retColor.r = 25;
            retColor.g = 160;
            retColor.b = 25;
            break;
        case 3:
            retColor.r = 160;
            retColor.g = 160;
            retColor.b = 25;
            break;
        case 4:
            retColor.r = 25;
            retColor.g = 160;
            retColor.b = 160;
            break;
        case 5:
            retColor.r = 255;
            retColor.g = 0;
            retColor.b = 0;
            break;
        case 6:
            retColor.r = 0;
            retColor.g = 160;
            retColor.b = 0;
            break;
        case 7:
            retColor.r = 0;
            retColor.g = 0;
            retColor.b = 255;
            break;
        default:
            retColor.r = 0;
            retColor.g = 0;
            retColor.b = 0;
            break;
    }
    return retColor;
}

void ircUserList::add(ircUser *userToAdd){
    userToAdd->setColor(getColor(this->users.count()));
    this->users.append(userToAdd);
}

void ircUserList::del(ircUser *userToDel){
    for(int i = 0; i < this->users.size(); i++){
        if(this->users[i]->getName() == userToDel->getName()){
            this->users.remove(i);
        }
    }
}

ircUser *ircUserList::getUser(const nickAndStatus nick, const QString id){
    ircUser *searched = this->getUserById(id);
    if(searched->getName() == "NaN"){
        searched = this->getUserByNick(nick);
        if(searched->getName() == "NaN"){
            return new ircUser;
        }else{
            return searched;
        }
    }else{
        return searched;
    }
}

ircUser *ircUserList::getUserByNick(nickAndStatus nick) {
    for(int i=0; i < this->users.size(); i++){
        if(this->users[i]->getName() == nick.nick){
            return &*this->users[i];
        }
    }
    return new ircUser();
}

ircUser *ircUserList::getUserById(QString id){
    for(int i=0; i < this->users.size(); i++){
        if(this->users[i]->getId() == id){
            return &*this->users[i];
        }
    }
    return new ircUser();
}

QVector<ircUser *> ircUserList::getAll() const{
    return this->users;
}
