#include "clsnotify.h"

namespace client{

    clsNotify::clsNotify(const QString title, const QString body, QObject *parent) :
        QObject(parent)
    {
#ifdef Q_OS_LINUX
        notify_init ("customIrcClient");
        this->thisNot = notify_notification_new (title.toStdString().c_str(),
                body.toStdString().c_str(),
                "dialog-information");
#endif
    }

    void clsNotify::show() const{
#ifdef Q_OS_LINUX
        notify_notification_show (this->thisNot, NULL);
#endif
    }

}
