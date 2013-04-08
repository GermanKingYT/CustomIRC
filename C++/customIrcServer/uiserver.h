#ifndef SIMPLECHATSERVER_H
#define SIMPLECHATSERVER_H

#include <QTcpServer>
#include <QList>
#include <QHash>
#include "uiclient.h"
#include "../resources/clslog.h"
#include "../resources/jsoncommand.h"

#define DEFAULT_LISTENING_PORT 1337 /*!< The default listening port for the UI server */

class QTcpSocket;

namespace server {
/*!
 * \brief The uiServer class
 * \author Koen Beckers (K-4U)
 * Listens for incoming connections
 */
class uiServer : public QTcpServer
{
	Q_OBJECT

public:
	/*!
	 * \brief uiServer constructor
	 * \param port The port to listen on, defaults to DEFAULT_LISTENING_PORT
	 * \param parent The QT parent object
	 */
    uiServer(int port = DEFAULT_LISTENING_PORT, QObject* parent = 0);
    ~uiServer();

	/*!
	 * \brief Starts to listen on the port.
	 */
    void startListen();


	/*!
	 * \brief Sends a jsonCommand to all the clients
	 * \param toSend The command to send
	 */
	void send(const jsonCommand &toSend);

	/*!
	 * \brief Sends a jsonCommand to given client
	 * \param client The client to send the command to
	 * \param toSend The command to send
	 */
    void send(uiClient *client, const jsonCommand &toSend);

private slots:
	/*!
	 * \brief Triggered when a client connects
	 */
    void acceptConnection();

	/*!
	 * \brief Triggered when a client disconnects
	 * \param client The client instance that disconnected
	 */
    void lostConnection(uiClient* client);

	/*!
	 * \brief Triggered when a client sends a chatmessage
	 * \param message The chatmessage received
	 */
    void chatReceived(QString message);

	/*!
	 * \brief Triggered when a client wants all the users
	 * \param client The client instance that wants the users
	 */
    void doUserQuery(uiClient *client);

	/*!
	 * \brief Triggered when a client wants all the events
	 * \param client The client instance that wants the events
	 */
    void doSendEvents(uiClient *client);

	/*!
	 * \brief Triggered when a client wants to change something about our own user
	 * \param comm The jsonCommand holding the data
	 * \todo Replace jsonCommand by something else
	 */
    void changeOwnUser(jsonCommand &comm);
signals:
	/*!
	 * \brief Emitted when a chatmessage has been send from a client
	 * \param message The message that has been sent
	 */
    void sgnChatReceived(QString message);

	/*!
	 * \brief Emitted when a client wants all the users
	 * \param client The client instance that wants the users
	 * \note This is DIRECTLY hooked to the slot doUserQuery of this class
	 */
    void sgnUserQuery(uiClient *client);
	/*!
	 * \brief Emitted when a client wants all the events
	 * \param client The client instance that wants the events
	 * \note This is DIRECTLY hooked to the slot doSendEvents of this class
	 */
    void sgnSendEvents(uiClient *client);

	/*!
	 * \brief Emitted when a client wants to change our own status
	 * \param newStatus The new status to take
	 */
    void sgnChangeOwnUserStatus(QString newStatus);


private:
    QList<uiClient*> connections;

    clsLog log;

    int port;
};

}
#endif // SIMPLECHATSERVER_H
