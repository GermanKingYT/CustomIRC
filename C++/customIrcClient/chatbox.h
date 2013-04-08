#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QVector>
#include <QTime>
#include "../resources/clsevent.h"
#include "ircuser.h"

#include "chatentry.h"
#include "chatnotification.h"

namespace Ui {
    class chatBox;
}

namespace client {

	/*!
	 * \brief UI Segment containing the chatbox
	 * \author Koen Beckers (K-4U)
	 */
    class chatBox : public QWidget
    {
        Q_OBJECT
		enum widgetTypes{
			WIDGETTYPES_CHATENTRY = 0x00,
			WIDGETTYPES_NOTIFICATION
		};
		struct content{
			widgetTypes type;
			QWidget *widget;
		};

	public:
        explicit chatBox(QWidget *parent = 0);
        ~chatBox();

		/*!
		 * \brief Adds a chat message to the box, Identified only by a user and a message
		 * \param user The user that sent the chatmessage
		 * \param message The chat message itself
		 */
        void addChat(ircUser *user, QString message);
		/*!
		 * \brief Adds a chat message to the box, Identified by a user, a message and a time
		 * \param user The user that sent the chatmessage
		 * \param message The chat message itself
		 * \param timeOfMessage The time on which the message was sent
		 */
        void addChat(ircUser *user, QString message, QTime timeOfMessage);

		/*!
		 * \brief Adds a notification to the chatbox
		 * \param message The notification to add
		 */
        void addMessage(QString &message);
		/*!
		 * \brief Adds a notification to the chatbox
		 * \param message The notification to add
		 */
        void addMessage(const QString &message);
		/*!
		 * \brief Adds a notification to the chatbox
		 * \param message The notification to add
		 */
        void addMessage(const char* msg);

		/*!
		 * \brief Sets all the user name labels to the same size
		 * \param newSize The new size
		 * This is called from a chatEntry, when it's new calculated width would be too large
		 */
        void setAllUserNameSize(int newSize);

	private:
        Ui::chatBox *ui;
        QVector<content*> entries;
        int widthOfNick;


    };

}
#endif // CHATBOX_H
