#ifndef IRCCLIENT_H
#define IRCCLIENT_H

#include <QVector>
#include <QTimer>
#include <QBuffer>
#include <QString>
#include <QTcpSocket>
#include <QStringList>
#include <QTextStream>
#include "ircCodes.h"
#include "functions.h"
#include "../resources/clslog.h"
#include "ircuser.h"

#define PORT 6667 /*!< Standard IRC Port*/
#define MAX_CONNECT_TIMEOUT_IN_MS	5000 /*!< Max timeout for connecting, in MS */
#define PING_THRESHOLD	50 /*!< How long ago a ping may have been send */
#define PING_CHECK_INTERVAL	5
namespace server {
/*!
 * \brief The ircClient class
 * \author Koen Beckers (K-4U)
 * My beautiful IRC Client.
 *
 */
class ircClient : public QObject{
    Q_OBJECT

public:
	/*!
	 * \brief ircClient constructor
	 * \param hostname The IRC host to connect to
	 * \param port The IRC port to connect to (if not standard)
	 * \param channel The channel to join
	 * \param nick The nick to use
	 */
	ircClient(const QString &hostname, const QString &channel, const QString &nick,
			  const int port = PORT);
    ~ircClient();

	/*!
	 * \brief connects to the IRC server. Sets the whole thing in motion
	 */
	void doConnect();

	/*!
	 * \brief Sets our own user.
	 * \param ownUser The user to set as ourselfes
	 */
	void setOwnUser(ircUser *ownUser);

	/*!
	 * \brief Sends a chat message to a certain channel.
	 * \param msg The message to send
	 * \param channel The channel to send it to
	 */
    void sendChat(const char *msg, const char *channel);
	/*!
	 * \brief Sends a chat message to the current channel.
	 * \param msg The message to send
	 */
    void sendChat(const char *msg);
	/*!
	 * \brief Sends a chat message to the current channel.
	 * \param msg The message to send
	 */
    void sendChat(const QString &msg);

	/*!
	 * \brief Sets our own user.
	 * \param user Our new user.
	 */
    void setUser(ircUser &user);
	/*!
	 * \brief getOwnNick
	 * \return Our own nickname. At that moment known to us.
	 */
    nickAndStatus getOwnNick() const;

	/*!
	 * \brief Sets our own nickname
	 * \param newNick The nickname to set
	 */
    void setOwnNick(const QString &newNick);
signals:
	/*!
	 * \brief Emitted when the client is logged in. MOTD has been received.
	 */
    void startupComplete();

	/*!
	 * \brief Emitted when a chatmessage has been received
	 * \param channel The channel in which the message has been received
	 * \param user The nick and status of the user sending the message
	 * \param message The message itself
	 */
    void chatReceived(const QString channel, const nickAndStatus user,
                      const QString message);

	/*!
	 * \brief Emitted when a user comes online with a JOIN message
	 * \param nickName The nick and status the user has.
	 * \param id The IRC-ID of this user
	 * \param channel The channel in which he has joined
	 */
    void userOnline(const nickAndStatus nickName, const QString id,
                    const QString channel);

	/*!
	 * \brief Emitted when a user leaves the room with a PART message
	 * \param nickName The nick and status the user had when he left
	 * \param id The IRC-ID of this user
	 * \param channel The channel which he left
	 */
    void userOffline(const nickAndStatus nickName, const QString id,
                     const QString channel);

	/*!
	 * \brief Emitted when a user changes his nickname (nick|Status)
	 * \param oldNickName The old nick and status this user had
	 * \param newNickName The new nick and status this user now has
	 * \param id His IRC-ID. The only thing probably that remained the same.
	 * \warning Not to be confused with userChangeStatus!
	 */
    void userChangeNick(const nickAndStatus oldNickName,
                        const nickAndStatus newNickName,
                        const QString id);
	/*!
	 * \brief Emitted when a user changes his status (nick|Status)
	 * \param oldNick The old nick and status this user had.
	 * \param newNick The new nick and status this user now has
	 * \param id His IRC-ID. The only thing probably that remained the same.
	 * \warning Not to be confused with userChangeNick!
	 */
    void userChangeStatus(const nickAndStatus oldNick,
                          const nickAndStatus newNick,
                          const QString id);

	/*!
	 * \brief Emitted when a connection cannot be made after MAX_CONNECT_TIMEOUT_IN_MS
	 */
	void IRCConnectTimeOut();

	/*!
	 * \brief Emitted when the connection has been established
	 */
	void IRCConnected();

	/*!
	 * \brief Emitted when the connection was cut!
	 */
	void IRCDisconnected(QString reason);

private:
	/*!
	 * \brief Initializes the IRC Client. Does not yet connect!
	 */
    void init();

	/*!
	 * \brief Sends a message to the IRC server
	 * \param data The data to send
	 */
    void send(const QString data);

	/*!
	 * \brief Handles a command sent from the irc server
	 * \param sender The IRC-ID that send the command
	 * \param command A string list containing the command
	 */
    void handleCommand(const QString &sender, const QStringList &command);

	/*!
	 * \brief Replies to the server ping
	 * \param packet
	 */
    void sendPong(const QString packet);

public slots:
    void disconnected();
	void sltConnected();
	/*!
	 * \brief Reads data from the IRC Socket
	 */
    void readData();
	void connectTimeout();

	/*!
	 * \brief Runs every CHECK_PING_INTERVAL to check if the last ping was there
	 */
	void checkForPing();
private:
	/*!
	 * \brief The hostname to which the IRC client has connected
	 */
    QString hostname;
	/*!
	 * \brief The port on which the IRC client has connected
	 */
    int port;
	/*!
	 * \brief The channel the IRC client joined
	 */
    QString channel;
	/*!
	 * \brief If the server has sent us the Message Of The Day
	 */
    bool motdReceived;

	/*!
	 * \brief The socket communicating with the IRC server
	 */
    QTcpSocket *sock;

	/*!
	 * \brief Buffer for receiving messages
	 */
    QBuffer *buffer;

	/*!
	 * \brief Log class for easy debugging
	 */
    clsLog log;

    nickAndStatus ownNickAndStatus;
    ircUser ownUser;
	bool connected;
	bool connecting;

	QTimer *connectTimer;
	QTimer *timeOutChecker;
	QTime lastPing;
	int timeBetweenPings;
	bool suppressDisconnectSignal;
};
}
#endif // IRCCLIENT_H
