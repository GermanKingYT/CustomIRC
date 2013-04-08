#ifndef CHATINPUT_H
#define CHATINPUT_H

#include <QPlainTextEdit>
#include <QList>
#include <QString>

namespace client{
	/*!
	 * \brief UI segment containing the chat input
	 * \author Koen Beckers (K-4U)
	 */
    class chatInput : public QPlainTextEdit
    {
        Q_OBJECT
        public:
            explicit chatInput(QWidget *parent = 0);


		Q_SIGNALS:
			/*!
			 * \brief Emitted when the user presses enter and the chatbox does not contain a command
			 * \param message The message to be sent
			 */
            void sendChat(QString message);
			/*!
			 * \brief Emitted when the users presses enter and the chatbox contains a command
			 * \param command The command send
			 * \param args A QList<QString> of arguments (split at space)
			 */
            void commandGiven(QString command, QList<QString> args);

		public slots:


        private:
			void keyPressEvent(QKeyEvent *e);
			void checkForCommand(QString text);
    };
}
#endif // CHATINPUT_H
