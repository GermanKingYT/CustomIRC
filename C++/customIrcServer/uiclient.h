#ifndef UICLIENT_H
#define UICLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonDocument>

#include "../resources/clslog.h"
#include "../resources/jsoncommand.h"

using namespace K4U;
namespace server {
/*!
 * \brief The uiClient class
 * \author Koen Beckers (K-4U)
 */
class uiClient: public QObject{
    Q_OBJECT
public:
	/*!
	 * \brief uiClient constructor
	 * \param parent The socket that the instance should handle
	 */
    uiClient(QTcpSocket *parent);
    
	/*!
	 * \brief Sends data to the socket
	 * \param data The data to send
	 */
    void send(QString data);


private:
	/*!
	 * \brief Adds data to buffer and checks for json commands
	 * \param toAdd The bytes to add
	 * \param comm Pointer to a jsonCommand to be filled
	 * \return true if a jsonCommand was detected
	 * Constantly looks for a JSON command in the buffer
	 * This is done with the depth.
	 * Every time a { or [ is detected, depth is raised.
	 * Every time a } or ] is detected, depth is decreased.
	 * When depth is 0, there should be a complete json command!
	 */
	bool checkForJsonCommand(QByteArray toAdd, jsonCommand *comm);
signals:

	/*!
	 * \brief Emitted when the user client disconnects
	 * \param client The instance of this class
	 */
    void disconnected(uiClient *client);
	/*!
	 * \brief Emitted when the client sends a chat
	 * \param message The message that the client wants to chat
	 */
    void chatReceived(QString message);
	/*!
	 * \brief Emitted when the client wants all the users
	 * \param client The instance of this class
	 */
    void userQuery(uiClient *client);
	/*!
	 * \brief Emitted when the client wants all the events
	 * \param client The instance of this class
	 */
    void getEvents(uiClient *client);

	/*!
	 * \brief Emitted when the clients wants to change our own user
	 * \param comm A jsonCommand with the data.
	 * \todo Replace the comm object with a QString or NickAndStatus!
	 */
    void changeOwnUser(jsonCommand &comm);

public slots:
    void removeConnection();
    void receiveMessage();

private:
    QTcpSocket *sock;
    clsLog log;
    QString *buffer;
    int depth;
};

}
#endif // UICLIENT_H
