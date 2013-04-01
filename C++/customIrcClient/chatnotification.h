#ifndef CHATNOTIFICATION_H
#define CHATNOTIFICATION_H

#include <QWidget>
#include <QLabel>
#include <QTime>

namespace Ui {
class chatNotification;
}

class chatNotification : public QWidget
{
    Q_OBJECT
    
public:
    explicit chatNotification(QString message, QWidget *parent = 0);
    ~chatNotification();
    
    void resizeEvent(QResizeEvent *event);
private:
    void calculateMessageWidth();
    int getHeight(QLabel *l) const;
    int getWidth(QLabel *l) const;

    Ui::chatNotification *ui;
    QString message;
    QTime timeOfMessage;
};

#endif // CHATNOTIFICATION_H
