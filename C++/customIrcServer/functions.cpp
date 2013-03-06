#include <QDateTime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "functions.h"


using namespace std;

string tagToStr(logTags tag){
    string ret = "";
    switch(tag){
        case LOGTAGS_IRC:
            ret = "IRC";
            break;
        case LOGTAGS_MAIN:
            ret = "MAIN";
            break;
        default:
            ret = "UNK";
            break;
    }
    return ret;
}
const char* fromQstringToCharArray(QString str){
    return str.toStdString().c_str();
}



void doLog(const logTags tag, const char* msg, ...){
    va_list ap;

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();
    cout << "[" << tagToStr(tag) << "]\t" << dateTimeString.toStdString() << "\t";

    va_start(ap, msg); //Requires the last fixed parameter (to get the address)
    vprintf(msg, ap);
    va_end(ap);

    cout << endl;
}
