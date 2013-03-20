#ifndef CLSLOG_H
#define CLSLOG_H
#include <QDebug>
#include <QDateTime>
#include <string>
#include <iostream>
#include <QStringList>

enum logTags{
    LOGTAGS_UNKNOWN = 0xFF,
    LOGTAGS_IRC = 0x00,
    LOGTAGS_MAIN,
    LOGTAGS_USER,
    LOGTAGS_SERVER,
    LOGTAGS_UI,
    LOGTAGS_WEB
};

class clsLog{
public:
    clsLog(logTags tag);

    clsLog& operator<<(clsLog& (*manip)(clsLog&));


    clsLog& operator << (QString msg);
    clsLog& operator << (const QString *msg);
    clsLog& operator << (const char* msg);
    clsLog& operator << (int msg);
    clsLog& operator << (clsLog *log);
    clsLog& operator << (bool msg);
    clsLog& operator << (QVariantMap &map);
    clsLog& operator << (const QVariantMap &map);
    clsLog& operator << (const QVariant &msg);
    clsLog& operator << (QVariant &msg);
    clsLog& operator << (QByteArray &bArr);
    clsLog& operator << (const QByteArray &bArr);



    void doEndl();
    void setPrefix(QString prefix);
private:
    bool isFirst;
    logTags tag;

    void prefix();
    std::string getTag();
    QString prf;
};

clsLog& endl(clsLog& log);




#endif // CLSLOG_H
