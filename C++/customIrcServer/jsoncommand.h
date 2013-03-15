#ifndef JSONCOMMAND_H
#define JSONCOMMAND_H

#include <QObject>
#include <QVariantMap>

#include "clslog.h"


//TODO: Command implement
enum jsonCommands{
    JSONCOMMAND_PING = 0x01,
    JSONCOMMAND_USERINFO,
    JSONCOMMAND_USERINFOREQ,
    JSONCOMMAND_CHAT
};


class jsonCommand{
public:
    jsonCommand(QVariantMap parent);
    jsonCommand(jsonCommands command);
    ~jsonCommand();

    jsonCommands getCommand() const;
    QString getCommandString() const;
    void setCommand(const jsonCommands& newCommand);

    QVariantMap getData() const;
    void setData(const QVariantMap& newData);
    void addToData(const QString key, const QVariant &data);

    friend clsLog& operator<<(clsLog& log, jsonCommand &command);

private:
    jsonCommands command;
    QVariantMap data;
};


#endif // JSONCOMMAND_H
