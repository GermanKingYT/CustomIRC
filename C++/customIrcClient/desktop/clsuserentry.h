#ifndef CLSUSERENTRY_H
#define CLSUSERENTRY_H

#include <QWidget>
#include <QLabel>
#include "../ircuser.h"

namespace Ui {
    class clsUserEntry;
}

namespace client{
	/*!
	 * \brief UI segment for a user entry in the user list
	 * \author Koen Beckers (K-4U)
	 */
    class clsUserEntry : public QWidget
    {
        Q_OBJECT

        public:
            explicit clsUserEntry(ircUser *user, QWidget *parent = 0);
            ~clsUserEntry();

            void refresh();
		private slots:
			void iconChanged();

        private:
            Ui::clsUserEntry *ui;

            ircUser *user;
    };

}
#endif // CLSUSERENTRY_H
