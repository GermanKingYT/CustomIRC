#include "clssettings.h"

clsSettings::clsSettings(const QString &fileName){
    QXmlStreamReader Rxml;
    QFile file(fileName + "/settings.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        std::cerr << "Error: Cannot read file " << fileName.toStdString()
         << ": " << qPrintable(file.errorString())
         << std::endl;
    }
    Rxml.setDevice(&file);
    Rxml.readNext();


    while(!Rxml.atEnd()){
        if(Rxml.isStartElement()){
            if(Rxml.name() == "settings"){
                Rxml.readNext(); //Start
            } else if(Rxml.name() == "server"){
                Rxml.readNext();
                this->readServer(Rxml);
            } else if(Rxml.name() == "users"){
                Rxml.readNext();
                this->readUsers(Rxml);
            } else if(Rxml.name() == "userInfo"){
                Rxml.readNext();
                this->readUserInfo(Rxml);
            }
        }
        Rxml.readNext();
   }
    file.close();
}

QString clsSettings::getServer() const{
    return this->server;
}

QString clsSettings::getChannel() const{
    return this->channel;
}

QString clsSettings::getUserName() const{
    return this->ownUser->getName();
}

ircUser *clsSettings::getOwnUser() const{
    return this->ownUser;
}

QVector<ircUser *> clsSettings::getUsers() const{
    return this->users;
}


void clsSettings::readServer(QXmlStreamReader &reader){
    while(!reader.isEndElement()){
        QString name = reader.name().toString();
        if(name == "server"){
            this->server = reader.readElementText();
        }else if(name == "channel"){
            this->channel = reader.readElementText();
        }
        reader.readNext();
    }
}

void clsSettings::readUsers(QXmlStreamReader &reader){
    while(!reader.isEndElement()){
        if(reader.name().toString() == "user"){
            reader.readNext();
            QString username;
            QString email;
            bool endElement = reader.isEndElement();
            while(!endElement){
                endElement = reader.isEndElement();
                QString name = reader.name().toString();
                if(name == "username"){
                    username = reader.readElementText();
                }else if(name == "email"){
                    email = reader.readElementText();
                }
                reader.readNext();
            }
            ircUser *myUser = new ircUser(username,true);
            myUser->setEmail(email);

            this->users.append(myUser);
        }
        reader.readNext();
    }
}

void clsSettings::readUserInfo(QXmlStreamReader &reader){
    QString username;
    QString email;
    while(!reader.isEndElement()){
        QString name = reader.name().toString();
        if(name == "username"){
            username = reader.readElementText();
        }else if(name == "email"){
            email = reader.readElementText();
        }
        reader.readNext();
    }
    this->ownUser = new ircUser(username,true);
    this->ownUser->setEmail(email);
    this->ownUser->setOnline(true);
}
