#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <QString>
#include <QStringList>
#include <QVariantList>


extern bool inCommand(const QString *command, const char* search);
extern const std::string qts(const QString str);
extern QStringList getStatus(const QString nick);
extern char getS(const char *msg, ...);

#endif // FUNCTIONS_H
