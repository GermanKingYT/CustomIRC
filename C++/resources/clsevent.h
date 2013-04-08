#ifndef CLSEVENT_H
#define CLSEVENT_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDateTime>

namespace shared{
/*!
 * \brief The eventTypes enum
 */
enum eventTypes{
	EVENTTYPE_NONE = 0x00, /*!< When all you need is an empty event */
	EVENTTYPE_CHAT, /*!< For when a chatmessage has been received */
	EVENTTYPE_USER_LEFT, /*!< For when a user left the channel */
	EVENTTYPE_USER_STATUS, /*!< For when a user updated his or her status */
	EVENTTYPE_USER_JOIN /*!< For when a user joins the channel */
};


/*!
 * \brief The main event class
 * \author Koen Beckers (K-4U)
 */
class clsEvent
{
public:
	/*!
	 * \brief Empty initializer function
	 */
    explicit clsEvent();
	/*!
	 * \brief Initializer function that accepts data immediately.
	 * \param data A QVariantMap containing the event data, parsed from JSON
	 * Mostly used on the receiving end.
	 */
    explicit clsEvent(QVariantMap data);

	/*!
	 * \brief Adds data to the events data map
	 * \param key The key to add the data under
	 * \param data The data to add
	 */
    void addToData(const QString &key, const QVariant data);

	/*!
	 * \brief Converts the current data to a QVariant for sending with JSON
	 * \return The event as a QVariant object
	 */
    QVariant toVariant() const;

	/*!
	 * \brief Get data from the events data map
	 * \param key The key to retrieve
	 * \return A QVariant containing the data
	 */
    QVariant getData(QString key) const;

	/*!
	 * \brief Gets this events type
	 * \return An eventTypes object containing the eventType
	 */
    eventTypes getType() const;

	/*!
	 * \brief Gets the time on which the event was created
	 * \return The time on which the event was created
	 */
	QTime getTime() const;


protected:
	/*!
	 * \brief The events data map
	 */
    QVariantMap data;
    eventTypes ourType;
    QDateTime timeOfEvent;

	/*!
	 * \brief Gets the event type as a string
	 * \return The event type as a string
	 */
    QString getEventType() const;

	/*!
	 * \brief Sets the event type as a string
	 * \param eventString The eventType as a string
	 */
    void setEventType(const QString eventString);
};


/*!
 * \brief Class containing a chatEvent
 * \author Koen Beckers (K-4U)
 */
class eventChat : public clsEvent
{
public:
	/*!
	 * \brief eventChat constructor taking a userId and a message
	 * \param userId The DB-ID of the user that sent the message
	 * \param message The message that was sent
	 */
    eventChat(int userId, QString message);

	/*!
	 * \brief Initializer function that accepts data immediately.
	 * \param data A QVariantMap containing the event data, parsed from JSON
	 * Mostly used on the receiving end.
	 */
    eventChat(QVariantMap data);

	/*!
	 * \brief Gets the DB-ID of the user that sent the message
	 * \return The DB-ID of the user that sent the message
	 */
    int getUser() const;
	/*!
	 * \brief Gets the chat message
	 * \return The chat message
	 */
    QString getMessage() const;
};

/*!
 * \brief Class containing a user JOIN event
 * \author Koen Beckers (K-4U)
 */
class eventUserJoin : public clsEvent
{
public:
	/*!
	 * \brief eventUserJoin constructor taking a userId and a message
	 * \param userId The DB-ID of the user that joined
	 * \param user A QVariantMap of the user that joined
	 */
    eventUserJoin(const int userId, QVariantMap user);

	/*!
	 * \brief Initializer function that accepts data immediately.
	 * \param data A QVariantMap containing the event data, parsed from JSON
	 * Mostly used on the receiving end.
	 */
    eventUserJoin(QVariantMap data);

	/*!
	 * \brief Gets the DB-ID of the user that joined
	 * \return The DB-ID of the user that joined
	 */
    int getUserId() const;

	/*!
	 * \brief Gets a QVariantMap of the user that joined
	 * \return A QVariantMap of the user that joined
	 */
	QVariantMap getUser() const;

};

/*!
 * \brief Class containing a user PART event
 * \author Koen Beckers (K-4U)
 */
class eventUserLeave : public clsEvent
{
public:
	/*!
	 * \brief eventUserLeave constructor taking only a userId
	 * \param userId The DB-ID of the user that left
	 */
	eventUserLeave(const int userId);

	/*!
	 * \brief Initializer function that accepts data immediately.
	 * \param data A QVariantMap containing the event data, parsed from JSON
	 * Mostly used on the receiving end.
	 */
	eventUserLeave(QVariantMap data);

	/*!
	 * \brief Gets the DB-ID of the user that left
	 * \return The DB-ID of the user that left
	 */
	int getUserId() const;
};

}
#endif // CLSEVENT_H
