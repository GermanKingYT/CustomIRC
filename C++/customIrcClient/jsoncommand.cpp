#include "jsoncommand.h"


jsonCommand::jsonCommand(QString json){
    QVariant data = QtJson::parse(json);
    QVariantMap parent = qvariant_cast<QVariantMap>(data);
    this->setCommandInt(parent["command"].toString());
    this->data = parent["data"].toMap();
}


jsonCommand::jsonCommand(QVariantMap parent)
{
    this->command = (jsonCommands) parent["command"].toInt();
    this->data = parent["data"].toMap();
}

jsonCommand::jsonCommand(jsonCommands command)
    :command(command)
{

}

jsonCommand::~jsonCommand(){
}


jsonCommands jsonCommand::getCommand() const{
    return this->command;
}

QString jsonCommand::getCommandString() const{
    QString ret = "";
    switch(this->command){
        case JSONCOMMAND_PING:
            ret = "PING";
            break;
        case JSONCOMMAND_CHAT:
            ret = "CHAT";
            break;
        case JSONCOMMAND_USERINFO:
            ret = "USERINFO";
            break;
        case JSONCOMMAND_USERINFOREQ:
            ret = "USERINFOREQ";
            break;
        case JSONCOMMAND_NONE:
            ret = "NONE";
            break;
        case JSONCOMMAND_OWNCHAT:
            ret = "OWNCHAT";
            break;
    }
    return ret;
}

void jsonCommand::setCommandInt(QString command){
    jsonCommands set = JSONCOMMAND_NONE;
    if(command == "PING"){
        set = JSONCOMMAND_PING;
    }else if(command == "CHAT"){
        set = JSONCOMMAND_CHAT;
    }else if(command == "USERINFO"){
        set = JSONCOMMAND_USERINFO;
    }else if(command == "USERINFOREQ"){
        set = JSONCOMMAND_USERINFOREQ;
    }else if(command == "OWNCHAT"){
        set = JSONCOMMAND_OWNCHAT;
    }
    this->command = set;
}

void jsonCommand::setCommand(const jsonCommands &newCommand){
    this->command = newCommand;
}

QVariantMap jsonCommand::getData() const{
    return this->data;
}

QVariant jsonCommand::getData(const QString key){
    return this->data[key];
}

void jsonCommand::setData(const QVariantMap &newData){
    this->data = newData;
}

void jsonCommand::addToData(const QString key, const QVariant &data){
    this->data.insert(key,data);
}

QString jsonCommand::toJsonString() const{
    QVariantMap vmRet;
    vmRet["command"] = this->getCommandString();
    vmRet["data"] = QVariant(this->getData());

    return QtJson::serialize(QVariant(vmRet));
}

clsLog& operator <<(clsLog &log, jsonCommand &command){
    log << "JSON command: " << command.getCommandString();
    log << " Data: " << endl << command.getData() << endl;
    return log;
}
