#ifndef JSONCOMMAND_H
#define JSONCOMMAND_H

#include <QObject>
#include <QVariantMap>

#include "json.h"
#include "clslog.h"


//TODO: Command implement
enum jsonCommands{
    JSONCOMMAND_NONE = 0x00,
    JSONCOMMAND_PING = 0x01,
    JSONCOMMAND_USERINFO,
    JSONCOMMAND_USERINFOREQ,
    JSONCOMMAND_USERQUERY,
    JSONCOMMAND_CHAT,
    JSONCOMMAND_OWNCHAT,
    JSONCOMMAND_CHANGEOWNUSER
};


class jsonCommand{
public:
    jsonCommand(QString json);
    jsonCommand(QVariantMap parent);
    jsonCommand(jsonCommands command);
    ~jsonCommand();

    jsonCommands getCommand() const;
    QString getCommandString() const;
    void setCommand(const jsonCommands& newCommand);
    void setCommandInt(QString command);

    QVariant getData(const QString key);
    QVariantMap getData() const;
    void setData(const QVariantMap& newData);
    void addToData(const QString key, const QVariant &data);


    friend clsLog& operator<<(clsLog& log, jsonCommand &command);
    friend clsLog& operator<<(clsLog& log, const jsonCommand &command);

    QString toJsonString() const;
private:
    jsonCommands command;
    QVariantMap data;
};


#endif // JSONCOMMAND_H
