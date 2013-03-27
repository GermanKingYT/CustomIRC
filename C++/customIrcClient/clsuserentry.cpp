#include "clsuserentry.h"
#include "ui_clsuserentry.h"

clsUserEntry::clsUserEntry(ircUser *user, QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::clsUserEntry)
    ,user(user)
{
    ui->setupUi(this);
    this->ui->lblUserName->setText(this->user->getNick());
    QString status = this->user->getStatus();
    if(status == ""){
        status = "Online";
    }

    this->ui->lblUserStatus->setText(status);

    QPalette palette = ui->lblUserName->palette();
    palette.setColor(ui->lblUserName->foregroundRole(), this->user->getColor());
    ui->lblUserName->setPalette(palette);
}

clsUserEntry::~clsUserEntry()
{
    delete ui;
}