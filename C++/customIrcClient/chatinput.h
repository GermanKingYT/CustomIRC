#ifndef CHATINPUT_H
#define CHATINPUT_H

#include <QPlainTextEdit>
#include <QList>
#include <QString>

class chatInput : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit chatInput(QWidget *parent = 0);
    

Q_SIGNALS:
    void sendChat(QString message);
    void commandGiven(QString command, QList<QString> args);
public slots:
    

private:
    void keyPressEvent(QKeyEvent *e);
    void checkForCommand(QString text);
};

#endif // CHATINPUT_H
