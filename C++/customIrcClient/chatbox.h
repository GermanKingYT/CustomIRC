#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include "chatentry.h"
#include <QVector>
#include "ircuser.h"

namespace Ui {
class chatBox;
}

class chatBox : public QWidget
{
    Q_OBJECT
    
public:
    explicit chatBox(QWidget *parent = 0);
    ~chatBox();
    

    void addChat(ircUser &user, QString message);
    void setAllUserNameSize(int newSize);
private:
    Ui::chatBox *ui;
    QVector<chatEntry*> entries;


};

#endif // CHATBOX_H
