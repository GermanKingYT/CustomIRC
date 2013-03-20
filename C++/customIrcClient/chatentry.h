#ifndef CHATENTRY_H
#define CHATENTRY_H

#include <QFrame>
#include <QLabel>
#include <QTime>
#include "ircuser.h"

namespace Ui {
class chatEntry;
}

class chatEntry : public QFrame
{
    Q_OBJECT
    
public:
    explicit chatEntry(ircUser &user, QString message, QWidget *parent = 0);
    ~chatEntry();
    
    void setUserWidth(int newWidth);

    void resizeEvent(QResizeEvent *event);
private:
    Ui::chatEntry *ui;
    ircUser name;
    QString message;
    int getWidth(QLabel *l) const;
    void calculateMessageWidth();

    QTime timeOfMessage;
};

#endif // CHATENTRY_H
