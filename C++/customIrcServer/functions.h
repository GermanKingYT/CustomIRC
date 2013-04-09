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

/*!
 * \brief Just an instring command. Checks if search is in command
 * \param command The haystack
 * \param search The needle
 * \return True when needle is found.
 */
extern bool inCommand(const QString *command, const char* search);

/*!
 * \brief Shorthand to convert a QString to a std::string
 * \param str The QString to convert
 * \return A std::string containing str
 */
extern const std::string qts(const QString str);

/*!
 * \brief Converts a nickname to a nickAndStatus (nick|status)
 * \param dNick The nickname to convert
 * \return A nickAndStatus object containing the nickname and status of the user
 */
extern nickAndStatus getNickAndStatus(const QString dNick);

/*!
 * \brief Converts a full IRC-ID to something without the nickname
 * \param fullId A complete IRC-ID (nick|status!name@host)
 * \return An IRC-ID usefull to us
 */
extern const QString getId(const QString fullId);

/*!
 * \brief Converts an IRC-ID to a nickAndStatus (nick|status)
 * \param id The IRC-ID to convert
 * \return A nickAndStatus object containing the nickname and status of the user
 */
extern nickAndStatus getNickAndStatusFromId(const QString id);



}
#endif // FUNCTIONS_H
