
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <QDebug>

#include "functions.h"

using namespace std;
namespace server{

const string qts(const QString str){
    return str.toStdString();
}

nickAndStatus getNickAndStatus(const QString dNick){
    nickAndStatus ret;
    QString nick = dNick;

    if(dNick.indexOf("!") >= 0){
        nick = dNick.left(nick.indexOf("!"));
    }
    if(nick.indexOf("|") >= 0){
        ret.nick = nick.left(nick.indexOf("|"));
        ret.status =  nick.mid(nick.indexOf("|")+1);
    }else{
        ret.nick = nick;
    }
    if(ret.nick.left(1) == ":"){
        ret.nick = ret.nick.mid(1);
    }
    return ret;
}

const QString getId(const QString full){
    return full.mid(full.indexOf("!")+1);
}



bool inCommand(const QString *command, const char* search){
    return (command->indexOf(search) >= 0);
}

char getS(const char* msg, ...){
    char endString[255];
    va_list ap;
    va_start(ap,msg);

    vsprintf(endString, msg, ap);
    va_end(ap);

    return *endString;
}

nickAndStatus getNickAndStatusFromId(const QString id){
    QString nick(id.left(id.indexOf("!")));
    return getNickAndStatus(nick);
}



}
