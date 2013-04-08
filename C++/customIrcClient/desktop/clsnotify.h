#ifndef CLSNOTIFY_H
#define CLSNOTIFY_H

//#define QT_NO_KEYWORDS// To prevent prevent symbol collisions between GTK+ and Qt
#include <QObject>
#ifdef Q_OS_LINUX
#undef signals
#include <libnotify/notify.h>
#else

#endif
namespace client{
	/*!
	 * \brief Notification class.
	 * \warning Does not work yet!
	 * \author Koen Beckers (K-4U)
	 */
    class clsNotify : public QObject
    {
        Q_OBJECT
        public:
            explicit clsNotify(const QString title, const QString body, QObject *parent = 0);

            void show() const;
            public slots:


        private:
#ifdef Q_OS_LINUX
			NotifyNotification *thisNot;
#endif
    };

}

#endif // CLSNOTIFY_H
