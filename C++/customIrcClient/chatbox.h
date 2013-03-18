#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include "chatentry.h"
#include <QVector>

namespace Ui {
class chatBox;
}

class chatBox : public QWidget
{
    Q_OBJECT
    
public:
    explicit chatBox(QWidget *parent = 0);
    ~chatBox();
    
private:
    Ui::chatBox *ui;
    QVector<chatEntry> entries;


};

#endif // CHATBOX_H
