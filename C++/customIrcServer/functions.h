#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <QString>
#include <QStringList>


enum logTags{
    LOGTAGS_IRC = 0x00,
    LOGTAGS_MAIN
};

extern bool inCommand(const QString *command, const char* search);
extern const std::string qts(const QString str);
extern void doLog(const logTags tag, const char* msg, ...);

extern QStringList getStatus(const QString nick);
#endif // FUNCTIONS_H
