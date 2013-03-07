#ifndef CLSLOG_H
#define CLSLOG_H
#include <QDebug>
#include <QDateTime>
#include <string>
#include <iostream>

enum logTags{
    LOGTAGS_UNKNOWN = 0xFF,
    LOGTAGS_IRC = 0x00,
    LOGTAGS_MAIN
};


class clsLog{
public:
    clsLog(logTags tag);

    clsLog& operator<<(clsLog& (*manip)(clsLog&));


    clsLog& operator<< (QString msg);
    clsLog& operator<< (const QString *msg);
    clsLog& operator<< (const char* msg);
    clsLog& operator<< (int msg);
    clsLog& operator<< (clsLog *log);

    void doEndl();
private:
    bool isFirst;
    logTags tag;

    void prefix();
    std::string getTag();
};

clsLog& endl(clsLog& log);




#endif // CLSLOG_H
