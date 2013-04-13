#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QScrollArea>
#include <QScrollBar>
#include <QTimer>
#include "../resources/clslog.h"
#include "../resources/clsevent.h"
#include "chatbox.h"
#include "clsserverconn.h"
#include "clssettings.h"

#ifdef DESKTOP
#include "desktop/clsnotify.h"
#endif

using namespace shared;
using namespace shared::events;
#define RECONNECT_IN_S 5
namespace Ui {
    class MainWindow;
}
namespace client{

	/*!
	 * \brief Main UI window
	 * \author Koen Beckers (K-4U)
	 * This main window is the same for android and desktop
	 * Please mind the defines
	 */
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:
            explicit MainWindow(QApplication *a, QWidget *parent = 0);
            ~MainWindow();

#ifdef ANDROID
            enum ScreenOrientation {
                ScreenOrientationLockPortrait,
                ScreenOrientationLockLandscape,
                ScreenOrientationAuto
            };
            // Note that this will only have an effect on Fremantle.
            void setOrientation(ScreenOrientation orientation);
            void showExpanded();
#endif


			void showMessage(QString msg, level lvl);
	private slots:
            void sendChat(QString message);
            void commandGiven(QString command, QList<QString> args);
            void moveScrollBarToBottom(int min, int max);


            void serverConnected();
            void serverDisconnected();

			/*!
			 * \brief Triggered when a chat has been received
			 * \param chatEvent An eventChat object containing more data
			 */
			void chatReceived(eventChat *chatEvent);
			/*!
			 * \brief Triggered when the user query came back
			 * \param users A QVector<ircUser*> that contains all the users online at that point
			 */
            void userQueryCompleted(QVector<ircUser*> users);
			/*!
			 * \brief Triggered when a user changes his status (nick|status)
			 * \param statusEvent An eventUserChangeStatus object containing more data
			 * \note Not to be confused with userChangeNick!
			 */
			void userStatusChange(eventUserChangeStatus *statusEvent);
			/*!
			 * \brief Triggered when a user changes his nick (nick|status)
			 * \param nickEvent An eventUserChangeNick object containing more data
			 * \note Not to be confused with userStatusChange
			 */
			void userChangeNick(eventUserChangeNick* nickEvent);

			/*!
			 * \brief Triggered when a user leaves the room
			 * \param leaveEvent An eventUserLeave object containing more data
			 */
            void userLeave(eventUserLeave *leaveEvent);

			/*!
			 * \brief Triggered when a user enters the room
			 * \param newUser An eventUserJoin object containing more data
			 */
            void userEnter(eventUserJoin *newUser);


			/*!
			 * \brief Triggered when the server sends us a message that should be displayed in the UI
			 * \param myMessage An eventServerMessage object containing more data
			 */
			void serverMessageReceived(eventServerMessage *myMessage);

			/*!
			 * \brief Triggered when we cannot connect to the server!
			 */
			void connectedTimeout();

			void doReconnect();
        private:
            Ui::MainWindow *ui;

            clsLog log;
            chatBox *cb;

            clsServerConn *server;

            QMap<int, ircUser *> users;

            clsSettings *settings;
			QTimer *reconnectTimer;
    };
}
#endif // MAINWINDOW_H
