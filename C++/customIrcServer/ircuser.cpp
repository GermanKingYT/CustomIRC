#include "ircuser.h"

ircUser::ircUser(const QString name, const QString id)
    :name(name)
    ,id(id)
    ,status("")
    ,online(true)
{
    if(this->name.left(1) == ":"){
        this->name = this->name.mid(1);
    }
    this->online = false;
    if(this->name.indexOf("|") >= 0){
        this->status = this->name.mid(this->name.indexOf("|")+1);
        this->name = this->name.left(this->name.indexOf("|"));
    }
}


ircUser::ircUser(const QString name, const bool standard)
    :name(name)
    ,id("NaN")
    ,status("Offline")
    ,online(false)
    ,standard(standard)
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
}

ircUser::ircUser(const QString name)
    :name(name)
    ,id("NaN")
    ,status("")
    ,online(true)
{
    if(this->name.left(1) == ":"){
        this->name = this->name.mid(1);
    }
    this->online = false;
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
{
}

QString ircUser::getName() const{
    return this->name;
}

QString ircUser::getStatus() const{
    return this->status;
}

void ircUser::setOnline(const bool isOnline){
    this->online = isOnline;
    if(this->online == false){
        if(this->standard == false){
            delete this;
        }
    }
}

bool ircUser::getOnline() const{
    return this->online;
}

void ircUser::setStatus(const QString &newStatus){
    this->status = newStatus;
}

void ircUser::setId(const QString *newId){
    this->id = *newId;
}
QString ircUser::getId() const{
    return this->id;
}


ircUserList::ircUserList(){
}

void ircUserList::add(ircUser *userToAdd){
    this->users.append(*userToAdd);
}


ircUser *ircUserList::findUser(ircUser &userToFind) {
    ircUser *searched = this->getUserByNick(userToFind.getName());
    if(searched->getName() == ""){
        return &userToFind;
    }else{
        return searched;
    }
}

ircUser *ircUserList::getUser(const QString nick, const QString id){
    ircUser *searched = this->getUserById(id);
    if(searched->getName() == ""){
        QStringList realNick = getStatus(nick);
        searched = this->getUserByNick(realNick [1]);
        if(searched->getName() == ""){
            return new ircUser;
        }else{
            return searched;
        }
    }else{
        return searched;
    }
}

ircUser *ircUserList::getUserByNick(QString nick) {
    for(int i=0; i < this->users.size(); i++){
        if(this->users[i].getName() == nick){
            return &this->users[i];
        }
    }
    return new ircUser("");
}

ircUser *ircUserList::getUserById(QString id){
    for(int i=0; i < this->users.size(); i++){
        if(this->users[i].getId() == id){
            return &this->users[i];
        }
    }
    return new ircUser("");
}

QVector<ircUser> ircUserList::getAll() const{
    return this->users;
}
