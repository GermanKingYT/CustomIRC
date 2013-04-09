#ifndef MAINAPP_H
#define MAINAPP_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include "ircclient.h"
#include "functions.h"
#include "ircuser.h"
#include "uiserver.h"
#include "uiclient.h"
#include "clssettings.h"
#include "../resources/clsevent.h"
#include "../resources/events/events.h"

#define MAX_EVENTS	5000 /*!< The maximum number of events stored before deleting the earliest */
#define RECONNECT_IN_S	10 /*!< Ammount of seconds it should take before starting to reconnect to the IRC */
using namespace shared;
using namespace shared::events;
namespace server {
/*!
 * \brief The main application
 * \author Koen Beckers (K-4U)
 */
class mainApp : public QObject
{
    Q_OBJECT
public:
    explicit mainApp(QString parentPath, QObject *parent = 0);
    void run();

	/*!
	 * \brief For logging to the clients
	 * \param message The message to log
	 */
	void serverMessage(const QString &message, const level lvl);
private:
	/*!
	 * \brief Adds an event to the history, checking for the maximum number
	 * \param event The event to add
	 * The event can be any event, as these classes are derived from eachother
	 */
	void addToEventHistory(clsEvent *event);

signals:
    
public slots:
	/*!
	 * \brief Triggered when a chat has been received
	 * \param channel The channel in which the chat has been received
	 * \param user The nick and status of the user that send the chat
	 * \param message The message
	 */
    void chatReceived(const QString channel, const nickAndStatus user,
                      const QString message);

	/*!
	 * \brief Triggered when a user joins trough a JOIN message
	 * \param nick The nick and status of the user that joins
	 * \param ircId The IRC-ID of the user that joins
	 * \param channel The channel in which the user has joined
	 */
    void userOnline(const nickAndStatus nick, const QString ircId,
                    const QString channel);

	/*!
	 * \brief Triggered when a user leaves trough a PART message
	 * \param nick The nick and status of the user that left
	 * \param id The IRC-ID of the user that left
	 * \param channel The channel which the user has left
	 */
    void userOffline(const nickAndStatus nick, const QString id,
                     const QString channel);

	/*!
	 * \brief Triggered when a user changes his nickname (nick|Status)
	 * \param oldNickName The old nick and status this user had
	 * \param newNickName The new nick and status this user now has
	 * \param id His IRC-ID. The only thing probably that remained the same.
	 * \warning Not to be confused with userChangeStatus!
	 */
    void userChangeNick(const nickAndStatus oldNick,
                        const nickAndStatus newNick,
                        const QString id);

	/*!
	 * \brief Triggered when a user changes his status (nick|Status)
	 * \param oldNick The old nick and status this user had
	 * \param newNick The new nick and status this user now has
	 * \param id His IRC-ID. The only thing probably that remained the same.
	 * \warning Not to be confused with userChangeNick!
	 */
    void userChangeStatus(const nickAndStatus oldNick,
                          const nickAndStatus newNick,
                          const QString id);

	/*!
	 * \brief Triggered when a UI client wants to send a chat message
	 * \param message The message to send
	 */
    void uiSendChat(const QString message);

	/*!
	 * \brief Triggered when a UI client wants all the users
	 * \param client The client which requested the user query
	 */
    void doUserQuery(uiClient *client);
	/*!
	 * \brief Triggered when a UI client wants all the events known to the server
	 * \param client The client which requested the events
	 */
    void doSendEvents(uiClient *client);

	/*!
	 * \brief Triggered when a UI client wants to change the status
	 * \param newStatus The status to change to
	 */
    void ownUserChangeStatus(QString newStatus);

	/*!
	 * \brief Triggered when the IRC client cannot connect
	 */
	void ircConnectTimeOut();

	/*!
	 * \brief Triggered when the IRC client has connected
	 */
	void ircConnected();
	/*!
	 * \brief Triggered when the IRC client has disconnected
	 */
	void ircDisconnected(QString reason);

	/*!
	 * \brief Emitted when the reconnect timer reaches 0
	 */
	void doIrcReconnect();
private:
    const static logTags TAG = LOGTAGS_MAIN;
    ircClient *irc;
    ircUserList *users;
    clsLog log;
    uiServer *ui;

    ircUser *ownUser;
    QVector<clsEvent *> events;

    clsSettings *settings;

	QTimer reconnectTimer;

};
}
#endif // MAINAPP_H
