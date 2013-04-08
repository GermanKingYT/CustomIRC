#ifndef IRCUSER_H
#define IRCUSER_H

#include <QString>
#include <QVector>
#include <QVariantMap>
#include "functions.h"
#include "../resources/clslog.h"

using namespace K4U;
namespace server {
/*!
 * \brief The ircUser class
 * \author Koen Beckers (K-4U)
 * Contains an IRC User
 * There are more than one way to create a user.
 * Please look at the options carefully!
 */
class ircUser {

public:
	/*!
	 * \brief The userColor struct
	 * As a replacement for the QColor type
	 */
    struct userColor{
        int r;
        int g;
        int b;
    };

	/*!
	 * \brief ircUser constructor
	 * \param name The nick and status of this user.
	 * \param ircId The IRC-id of this user
	 */
    ircUser(const nickAndStatus name, const QString ircId);

	/*!
	 * \brief ircUser constructor
	 * \param name The nickname of this user
	 * \param standard If the user is a regular user
	 * Usually this is used when loading users from a settings file.
	 */
    ircUser(const QString name, const bool standard);

	/*!
	 * \brief ircUser constructor
	 * \param name The nickname of this user
	 * Use of this constructor is highly discouraged as it cannot tell everything
	 * about a user!
	 */
    ircUser(const nickAndStatus name);

    ircUser();

    //Getters
	QString getName() const;
    bool getOnline() const;
    QString getStatus() const;
    bool isStandard() const;
	/*!
	 * \brief Used to convert a user for JSON transfer
	 * \return A variant map with all of the users´ data.
	 */
    QVariantMap toVariantMap() const;

	/*!
	 * \brief getIrcId
	 * \return The IRC-ID of this user.
	 * \warning Do not confuse with getId(), which returns the user Id in the database
	 */
    QString getIrcId() const;
	/*!
	 * \brief getId
	 * \return The ID of this user in the database
	 * \warning Do not confuse with getIrcId(), which returns the IRC-ID
	 */
    int getId() const;

    //Setters
    void setOnline(const bool isOnline);
    void setStatus(const QString &newStatus);
    void setIrcId(const QString &newId);
    void setId(const int &newId);
    void setNick(const QString &newNick);
    void setColor(const int r, const int g, const int b);
    void setColor(const userColor &newColor);
    void setEmail(const QString &email);


    friend clsLog& operator<<(clsLog& log, const ircUser* user);

private:
    QString name;
    QString ircId;
    int id;
    QString status;
    QString email;
    bool online;
    bool standard;

    userColor uColor;

    clsLog log;
};

/*!
 * \brief Contains all the users
 * \author Koen Beckers (K-4U)
 */
class ircUserList {
public:
    ircUserList();

	/*!
	 * \brief Adds a user to the list
	 * \param userToAdd
	 */
    void add(ircUser *userToAdd);
	/*!
	 * \brief Removes a user from the list
	 * \param userToDel
	 */
    void del(ircUser *userToDel);

	/*!
	 * \brief Finds a user based on his nick and status
	 * \param nick The nick and status to search for.
	 * \return A pointer to the correct ircUser object if found. Else a pointer to 0x00
	 */
    ircUser *getUserByNick(nickAndStatus nick);
	/*!
	 * \brief Finds a user based on IRC-ID or nick
	 * \param nick The nick and status to search for
	 * \param ircId The IRC-ID to search for
	 * \return A pointer to the correct ircUser object if found. Else a pointer to 0x00
	 */
    ircUser *getUser(const nickAndStatus nick, const QString ircId);

	/*!
	 * \brief Finds a user based on an exact copy
	 * \param userToFind The user to find
	 * \return A pointer to the correct ircUser object if found. Else a pointer to 0x00
	 * \note Not sure why this function exists. If you have the user, why would you want to find it again?
	 */
    ircUser *findUser(ircUser &userToFind);

	/*!
	 * \brief Gets a user by his database ID
	 * \param id The ID to search for
	 * \return A pointer to the correct ircUser object if found. Else a pointer to 0x00
	 * \warning Do not confuse this with getUserByIrcId which searches for a user based on his IRC-ID!
	 */
    ircUser *getUserById(int id);
	/*!
	 * \brief Gets a user by his IRC-ID
	 * \param ircId The IRC-ID to search for
	 * \return A pointer to the correct ircUser object if found. Else a pointer to 0x00
	 * \warning Do not confuse this with getUserById which searches for a user based on his database ID!
	 */
    ircUser *getUserByIrcId(QString ircId);

	/*!
	 * \brief Get all the users. Used for foreach
	 * \return A vector with pointers to all the users.
	 */
    QVector<ircUser*> getAll() const;


private:
    QVector<ircUser*> users;
    int lastId;
};

}
#endif // IRCUSER_H
