#ifndef MAINAPP_H
#define MAINAPP_H

#include <QObject>
#include "ircclient.h"
#include "functions.h"


class mainApp : public QObject
{
    Q_OBJECT
public:
    explicit mainApp(QObject *parent = 0);
    void run();


signals:
    
public slots:
    
private:
    const static logTags TAG = LOGTAGS_MAIN;
    ircClient *irc;
};

#endif // MAINAPP_H
