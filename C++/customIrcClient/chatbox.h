#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QVector>
#include <QTime>
#include "../resources/clsevent.h"
#include "ircuser.h"

#include "chatentry.h"
#include "chatnotification.h"

namespace Ui {
class chatBox;
}

class chatBox : public QWidget
{
    enum widgetTypes{
        WIDGETTYPES_CHATENTRY = 0x00,
        WIDGETTYPES_NOTIFICATION
    };

    Q_OBJECT
    struct content{
        widgetTypes type;
        QWidget *widget;
    };
    
public:
    explicit chatBox(QWidget *parent = 0);
    ~chatBox();
    

    void addChat(ircUser *user, QString message);
    void addChat(ircUser *user, QString message, QTime timeOfMessage);
    void addMessage(QString &message);
    void addMessage(const QString &message);
    void addMessage(const char* msg);
    void setAllUserNameSize(int newSize);
private:
    Ui::chatBox *ui;
    QVector<content*> entries;
    int widthOfNick;


};

#endif // CHATBOX_H
