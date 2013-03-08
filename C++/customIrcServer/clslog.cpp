#include "clslog.h"

using namespace std;

clsLog::clsLog(logTags tag)
    :isFirst(true)
    ,tag(tag)
{}


clsLog &clsLog::operator <<(clsLog &(*manip)(clsLog &)){
    return manip(*this);
}

clsLog &clsLog::operator <<(bool msg){
    if(msg == true){
        std::cout << "True";
    }else{
        std::cout << "False";
    }
    return *this;
}

clsLog &endl(clsLog &log){
    log.doEndl();
    return log;
}

void clsLog::doEndl(){
    std::cout << std::endl;
    isFirst = true;
}

void clsLog::prefix(){
    if(isFirst == true){
        isFirst = false;
        QDateTime dateTime = QDateTime::currentDateTime();
        QString dateTimeString = dateTime.toString();

        std::cout << "[" << this->getTag() << "]\t";
        std::cout << dateTimeString.toStdString() << "\t\t";
    }
}

clsLog& clsLog::operator <<(QString msg){
    this->prefix();
    std::cout << msg.toStdString();

    return *this;
}

clsLog &clsLog::operator <<(const QString *msg){
    this->prefix();
    std::cout << msg->toStdString();

    return *this;
}

clsLog& clsLog::operator <<(const char *msg){
    this->prefix();
    std::cout << msg;

    return *this;
}

clsLog& clsLog::operator <<(int msg){
    this->prefix();
    std::cout << msg;

    return *this;
}


std::string clsLog::getTag(){
    string ret = "";
    switch(this->tag){
        case LOGTAGS_IRC:
            ret = "IRC";
            break;
        case LOGTAGS_MAIN:
            ret = "MAIN";
            break;
        case LOGTAGS_USER:
            ret= "USER";
            break;
        default:
            ret = "UNK";
            break;
    }
    return ret;
}

