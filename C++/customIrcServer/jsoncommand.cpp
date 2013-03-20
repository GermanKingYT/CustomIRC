#include "jsoncommand.h"


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
    }
    return ret;
}

void jsonCommand::setCommand(const jsonCommands &newCommand){
    this->command = newCommand;
}

QVariantMap jsonCommand::getData() const{
    return this->data;
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
    log << " Data: " << endl << command.getData();
    return log;
}
