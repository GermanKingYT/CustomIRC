#ifndef CLSSERVERCONN_H
#define CLSSERVERCONN_H

#include <QObject>
#include <QTcpSocket>
#include <QTextStream>
#include <QTime>
#include "../resources/clslog.h"
#include <QBuffer>
#include "ircuser.h"
#include "../resources/jsoncommand.h"
#include "../resources/json.h"
#include "../resources/clsevent.h"

using namespace shared;
namespace client{

	/*!
	 * \brief Class that has a connection to the server
	 * \author Koen Beckers (K-4U)
	 */
    class clsServerConn : public QObject
    {
        Q_OBJECT
        public:
			/*!
			 * \brief Constructor taking a hostname and port
			 * \param hostName The hostname to connect to
			 * \param port The port to connect on
			 * \param parent The parent widget, Not allways used
			 * \note This only initializes the socket, it does not connect!
			 */
            explicit clsServerConn(const QString hostName, const int port,
                    QObject *parent = 0);

			/*!
			 * \brief Actually connect
			 */
            void doConnect();
			/*!
			 * \brief Send a JSON command to the server
			 * \param toSend jsonCommand that should be sent
			 */
            void sendCommand(jsonCommand &toSend);



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
			bool checkForJsonCommand(QByteArray toAdd, jsonCommand &comm);
			/*!
			 * \brief The server has given us all the users. Handle it
			 * \param comm The jsonCommand containing all the data
			 */
			void handleCompletedQuery(jsonCommand &comm);
			/*!
			 * \brief handleUser
			 * \param command
			 * \deprecated
			 */
			void handleUserInfo(jsonCommand &command);

			/*!
			 * \brief Another client has changed our own user status
			 * \param comm The jsonCommand containing all the data
			 */
			void handleOwnUserChange(jsonCommand &comm);

			/*!
			 * \brief Event request has been done by us, and data has been returned
			 * \param comm The jsonCommand containing all the events
			 */
			void handleEventRequest(jsonCommand &comm);

			/*!
			 * \brief Event has been received by the client. Parse it
			 * \param data A QVariantMap containing all the data
			 */
			void handleEventReceived(QVariantMap data);

signals:
			/*!
			 * \brief Emitted when a chat event has been received
			 * \param event
			 */
            void chatReceived(eventChat* event);
			/*!
			 * \brief Emitted when the client has a succesfull connection to the server
			 */
            void connected();
			/*!
			 * \brief Emitted when the client lost connection to the server
			 */
            void disconnected();

			/*!
			 * \brief Emitted when the server has sent us all the users
			 * \param users A QVector<ircUser*> of all the users
			 */
            void userQueryCompleted(QVector<ircUser*> users);

			/*!
			 * \brief Emitted when a user has changed his status (nick|status)
			 * \param userId The DB-ID of the user
			 * \param newStatus The new status of the user
			 * \note Not to be confused with userChangeNick!
			 */
            void userStatusChange(int userId, QString newStatus);

			/*!
			 * \brief Emitted when a user has changed his nick (nick|status)
			 * \param userId The DB-ID of the user
			 * \param newNick The new nick of the user
			 * \note Not to be confused with userStatusChange
			 */
            void userChangeNick(int userId, QString newNick);

			/*!
			 * \brief Triggered when a user left the channel
			 * \param leaveEvent An eventUserLeave containing more data
			 */
            void userLeave(eventUserLeave *leaveEvent);

			/*!
			 * \brief Triggered when a user enters the channel
			 * \param newUser An eventUserJoin containing more data
			 */
            void userEnter(eventUserJoin *newUser);

		public slots:
			void srvDisconnected();
            void srvConnected();
            void readData();

        private:
            QString hostName;
            int port;

            QTcpSocket *sock;
            QString *buffer;
            int depth;

            clsLog log;


    };
}
#endif // CLSSERVERCONN_H
