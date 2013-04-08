#ifndef CHATENTRY_H
#define CHATENTRY_H

#include <QFrame>
#include <QLabel>
#include <QTime>
#include "ircuser.h"

namespace Ui {
    class chatEntry;
}
namespace client{

	/*!
	 * \brief Class that holds a chatmessage for UI
	 * \author Koen Beckers (K-4U)
	 */
    class chatEntry : public QFrame
    {
        Q_OBJECT

        public:
			/*!
			 * \brief Constructor not taking a time
			 * \param user The user that sent the message
			 * \param message The chat message itself
			 * \param width The width of the nick label
			 * \param parent The parent widget
			 */
            explicit chatEntry(ircUser *user, QString message, int width,
                    QWidget *parent = 0);
			/*!
			 * \brief Constructor taking a time as argument
			 * \param user The user that sent the message
			 * \param message The chat message itself
			 * \param width The width of the nick label
			 * \param timeOfMessage The time at which the message was sent
			 * \param parent The parent widget
			 */
			explicit chatEntry(ircUser *user, QString message, int width,
                    QTime timeOfMessage, QWidget *parent = 0);
            ~chatEntry();

			/*!
			 * \brief Used for setting the width of the nick label after initializing
			 * \param newWidth The new width
			 */
            void setUserWidth(int newWidth);

            void resizeEvent(QResizeEvent *event);


        private:
            Ui::chatEntry *ui;
            ircUser *name;
            QString message;
            int getWidth(QLabel *l) const;
            int getHeight(QLabel *l) const;
            void init(QWidget *parent, int width);
            void calculateMessageWidth();

            QTime timeOfMessage;
    };
}
#endif // CHATENTRY_H
