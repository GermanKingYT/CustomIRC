#ifndef clsUserList_H
#define clsUserList_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QWidget>
#include <QVector>
#include "clsuserentry.h"
#include "../ircuser.h"

namespace Ui {
    class clsUserList;
}
namespace client{

	/*!
	 * \brief UI Segment for user list
	 * \author Koen Beckers (K-4U)
	 */
    class clsUserList : public QWidget
    {
        Q_OBJECT

        public:
            explicit clsUserList(QWidget *parent = 0);
            ~clsUserList();

			/*!
			 * \brief Adds a user to the list
			 * \param user The user to be added
			 */
            void addUser(ircUser *user);
			/*!
			 * \brief Refreshes a user entry
			 * \param user The user to be refreshed
			 */
            void refreshUser(ircUser *user);
			/*!
			 * \brief Removes a user entry
			 * \param user The user to be removed
			 */
            void removeUser(ircUser *user);
        private:
            void setupUi();
            QVBoxLayout *verticalLayout;
            QSpacerItem *verticalSpacer;

            QMap<ircUser*,clsUserEntry*> users;


    };
}
#endif // clsUserList_H
