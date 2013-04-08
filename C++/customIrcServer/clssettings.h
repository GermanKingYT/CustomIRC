#ifndef CLSSETTINGS_H
#define CLSSETTINGS_H

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QVector>
#include "ircuser.h"

#define DEFAULT_LISTEN_PORT 1337

namespace server {
/*!
 * \brief Settings class
 * \author Koen Beckers (K-4U)
 * Gets the settings from the xml file called settings.xml
 */

class clsSettings
{
public:
	/*!
	 * \brief clsSettings Constructor
	 * \param filePath the path where the settings.xml file is located
	 */
    clsSettings(const QString &filePath);

	/*!
	 * \brief getListeningPort
	 * \return the port where the server should listen on
	 */
    int getListeningPort() const;

	/*!
	 * \brief getServer
	 * \return the host where the IRC Server is running
	 */
    QString getServer() const;

	/*!
	 * \brief getChannel
	 * \return the channel to connect to.
	 */
    QString getChannel() const;

	/*!
	 * \brief getUserName
	 * \return the username to use for the bot.
	 */
    QString getUserName() const;

	/*!
	 * \brief getOwnUser
	 * \return our own user as an ircUser object.
	 */
    ircUser *getOwnUser() const;

	/*!
	 * \brief getUsers
	 * \return the 'standard' users which are always online.
	 */
    QVector<ircUser *> getUsers() const;
private: //Functions
	/*!
	 * \brief readUiSettings
	 * \param reader
	 * Parses the xml file opened by reader and fetches uiSettings
	 */
    void readUiSettings(QXmlStreamReader &reader);

	/*!
	 * \brief readServer
	 * \param reader
	 * Parses the xml file opened by reader and fetches irc server info
	 */
    void readServer(QXmlStreamReader &reader);

	/*!
	 * \brief readUsers
	 * \param reader
	 * Parses the xml file opened by reader and fetches the standard users
	 */
    void readUsers(QXmlStreamReader &reader);

	/*!
	 * \brief readUserInfo
	 * \param reader
	 * Parses the xml file opened by reader and fetches the own user settings
	 */
    void readUserInfo(QXmlStreamReader &reader);


private: //Values
	/*!
	 * \brief server
	 * Stores the irc server host
	 */
    QString server;

	/*!
	 * \brief channel
	 * Stores the irc channel
	 */
    QString channel;

	/*!
	 * \brief ownUser
	 * Stores the own user to connect with
	 */
    ircUser *ownUser;

	/*!
	 * \brief listeningPort
	 * The port for the uiServer to listen on
	 */
    int listeningPort;

	/*!
	 * \brief users
	 * The 'standard' users
	 */
    QVector<ircUser*> users;

};
}
#endif // CLSSETTINGS_H
