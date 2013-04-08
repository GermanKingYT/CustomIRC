#ifndef IRCUSER_H
#define IRCUSER_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QGraphicsView>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "../resources/clslog.h"

using namespace K4U;
namespace client{

	/*!
	 * \brief The ircUser class
	 * \author Koen Beckers (K-4U)
	 * Contains an IRC User
	 * There are more than one way to create a user.
	 * Please look at the options carefully!
	 */
    class ircUser : public QObject
    {
        Q_OBJECT

        public:
			/*!
			 * \brief ircUser constructor taking a QVariant for the jsonData
			 * \param jsonData The QVariant containing the JSON data
			 */
            explicit ircUser(QVariant jsonData);
			/*!
			 * \brief ircUser constructor taking all the users data
			 * \param id The DB-ID of this user
			 * \param nick The nickname of this user
			 * \param status The status of this user
			 * \param uColor The user color
			 * \param standard Determines if he should be removed or left in the list when he leaves
			 */
            explicit ircUser(qint32 id, QString nick, QString status, QColor uColor, bool standard);

            void copyFrom(ircUser *userToCopy);
            ~ircUser();

            //Getters
            const QString getNick() const;
            qint32 getId() const;
            const QString getStatus() const;
            const QColor getColor() const;
            const QString getEmail() const;
            const QPixmap getIcon() const;
            bool getStandard() const;
            bool getOnline() const;

            //Setters
            void setNick(const QString &newNick); //Probably never used
            void setStatus(const QString &newStatus);
            void setColor(const QColor &newColor); //Also probably never used
            void setEmail(const QString &email);
            void setOnline(const bool isOnline);



		signals:
            void iconChanged() const;

		private slots:
                void slot_netwManagerFinished(QNetworkReply* reply);

        private:
            qint32 id;
            QString nick;
            QString status;
            QColor uColor;
            bool standard;
            QString email;
            QPixmap icon;
            bool online;

            clsLog log;
    };
}
#endif // IRCUSER_H
