#include "chatentry.h"
#include "ui_chatentry.h"

chatEntry::chatEntry(QString username, QString message, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::chatEntry),
    name(username),
    message(message)
{
    ui->setupUi(this);
    this->ui->lblNick->setText(this->name + ":");
    this->ui->lblChat->setText(this->message);
}

chatEntry::~chatEntry()
{
    delete ui;
}
