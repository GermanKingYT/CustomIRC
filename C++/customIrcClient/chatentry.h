#ifndef CHATENTRY_H
#define CHATENTRY_H

#include <QFrame>

namespace Ui {
class chatEntry;
}

class chatEntry : public QFrame
{
    Q_OBJECT
    
public:
    explicit chatEntry(QString username, QString message, QWidget *parent = 0);
    ~chatEntry();
    
private:
    Ui::chatEntry *ui;
    QString name;
    QString message;
};

#endif // CHATENTRY_H
