#ifndef CHATINPUT_H
#define CHATINPUT_H

#include <QPlainTextEdit>

class chatInput : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit chatInput(QWidget *parent = 0);
    

signals:
    void sendChat(QString message);
public slots:
    

private:
    void keyPressEvent(QKeyEvent *e);
};

#endif // CHATINPUT_H
