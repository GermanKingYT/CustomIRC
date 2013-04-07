#ifndef CLSSETTINGS_H
#define CLSSETTINGS_H

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QVector>
#include "ircuser.h"


class clsSettings
{
public:
    clsSettings(const QString &filePath);


    QString getServer() const;
    int getPort() const;
private: //Functions
    void readServer(QXmlStreamReader &reader);


private: //Values
    QString server;
    int port;
};

#endif // CLSSETTINGS_H
