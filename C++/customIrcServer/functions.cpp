
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "functions.h"


using namespace std;

const string qts(const QString str){
    return str.toStdString();
}

QStringList getStatus(const QString nick){
    QStringList ret;
    if(nick.indexOf("|") >= 0){
        ret.append(nick.mid(nick.indexOf("|")+1));
        ret.append(nick.left(nick.indexOf("|")));
    }else{
        ret.append("");
        ret.append(nick);
    }
    return ret;
}

QString getId(const QString full){
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
/*
void doLog(const logTags tag, const QStringstream){

}*/

/*
void doLog(const logTags tag, const char* msg, QStringList args){
    va_list ap;

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();
    cout << "[" << tagToStr(tag) << "]\t" << dateTimeString.toStdString() << "\t";

    va_start(ap, msg); //Requires the last fixed parameter (to get the address)
    vprintf(msg, ap);
    va_end(ap);

    cout << endl;
}
*/
