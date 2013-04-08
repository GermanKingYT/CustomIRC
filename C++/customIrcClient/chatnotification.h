#ifndef CHATNOTIFICATION_H
#define CHATNOTIFICATION_H

#include <QWidget>
#include <QLabel>
#include <QTime>

namespace Ui {
    class chatNotification;
}
namespace client{

	/*!
	 * \brief UI Segment containing a notification in the chatbox
	 * \author Koen Beckers (K-4U)
	 */
    class chatNotification : public QWidget
    {
        Q_OBJECT

        public:
			/*!
			 * \brief Constructor taking a message
			 * \param message The message to be shown
			 * \param parent The parent widget
			 */
            explicit chatNotification(QString message, QWidget *parent = 0);
            ~chatNotification();

            void resizeEvent(QResizeEvent *event);
        private:
			/*!
			 * \brief Calculates the message width to detirmine it should be wrapped
			 */
            void calculateMessageWidth();
            int getHeight(QLabel *l) const;
            int getWidth(QLabel *l) const;

            Ui::chatNotification *ui;
            QString message;
            QTime timeOfMessage;
    };
}
#endif // CHATNOTIFICATION_H
