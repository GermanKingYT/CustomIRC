#ifndef CLSSERVERCONN_H
#define CLSSERVERCONN_H

#include <QObject>
#include <QTcpSocket>
#include <QTextStream>
#include <QTime>
#include "../resources/clslog.h"
#include <QTimer>
#include "ircuser.h"
#include "../resources/jsoncommand.h"
#include "../resources/json.h"
#include "../resources/clsevent.h"
#include "../resources/events/events.h"


#define MAX_CONNECT_TIMEOUT_IN_MS 5000

using namespace shared;
using namespace shared::events;
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
			 * \param changeEvent An eventUserChangeStatus containing more data
			 * \note Not to be confused with userChangeNick!
			 */
			void userStatusChange(eventUserChangeStatus *changeEvent);

			/*!
			 * \brief Emitted when a user has changed his nick (nick|status)
			 * \param changeEvent And eventUserChangeNick containing more data
			 * \note Not to be confused with userStatusChange
			 */
			void userChangeNick(eventUserChangeNick *changeEvent);

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

			/*!
			 * \brief Triggered when the server wants us to know something
			 * \param theMessage The message it sends
			 */
			void serverMessageReceived(eventServerMessage *theMessage);

			/*!
			 * \brief Triggered when it cannot connect.
			 */
			void sgnConnectTimeout();
		public slots:
			void srvDisconnected();
            void srvConnected();
            void readData();
			void connectTimeout();

        private:
            QString hostName;
            int port;

            QTcpSocket *sock;
            QString *buffer;
            int depth;

            clsLog log;

			QTimer *connectTimer;
			bool isConnected;
			bool isConnecting;


    };
}
#endif // CLSSERVERCONN_H
