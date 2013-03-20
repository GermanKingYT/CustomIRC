#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "clslog.h"
#include "chatbox.h"
#include "clsserverconn.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

private:
    Ui::MainWindow *ui;

    clsLog log;
    chatBox *cb;

    clsServerConn *server;
};

#endif // MAINWINDOW_H
