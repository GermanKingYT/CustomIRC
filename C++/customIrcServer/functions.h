#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <QString>
#include <QStringList>
#include <QVariantList>

namespace server{
/*!
 * \brief The nickAndStatus struct
 *
 */
struct nickAndStatus{
	QString nick;
	QString status;
};

extern bool inCommand(const QString *command, const char* search);

extern const std::string qts(const QString str);

extern nickAndStatus getNickAndStatus(const QString dNick);
extern nickAndStatus getNickAndStatusFromId(const QString id);

extern char getS(const char *msg, ...);


extern const QString getId(const QString fullId);

}
#endif // FUNCTIONS_H
