#ifndef clsUserList_H
#define clsUserList_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QWidget>
#include <QVector>
#include "clsuserentry.h"
#include "ircuser.h"

namespace Ui {
class clsUserList;
}

class clsUserList : public QWidget
{
    Q_OBJECT
    
public:
    explicit clsUserList(QWidget *parent = 0);
    ~clsUserList();
    

    void addUser(ircUser *user);
    void refreshUser(ircUser *user);
    void removeUser(ircUser *user);
private:
    void setupUi();
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;

    QMap<ircUser*,clsUserEntry*> users;


};

#endif // clsUserList_H
