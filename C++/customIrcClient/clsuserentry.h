#ifndef CLSUSERENTRY_H
#define CLSUSERENTRY_H

#include <QWidget>
#include <QLabel>
#include "ircuser.h"

namespace Ui {
class clsUserEntry;
}

class clsUserEntry : public QWidget
{
    Q_OBJECT
    
public:
    explicit clsUserEntry(ircUser *user, QWidget *parent = 0);
    ~clsUserEntry();
    
private:
    Ui::clsUserEntry *ui;
    ircUser *user;
};

#endif // CLSUSERENTRY_H
