#include "chatentry.h"
#include "ui_chatentry.h"
#include <math.h>
#include "chatbox.h"

chatEntry::chatEntry(ircUser *user, QString message, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::chatEntry),
    name(user),
    message(message),
    timeOfMessage(QTime::currentTime())
{
    ui->setupUi(this);
    this->setMinimumWidth(parent->width());
    this->ui->lblTime->setText(this->timeOfMessage.toString());
    this->ui->lblNick->setText(this->name->getNick() + ":");
    QPalette palette = ui->lblNick->palette();
    palette.setColor(ui->lblNick->foregroundRole(), this->name->getColor());
    ui->lblNick->setPalette(palette);

    this->message.replace(QRegExp("((?:https?|ftp)://\\S+)"), "<a href=\"\\1\">\\1</a>");

    this->ui->lblChat->setText(this->message);

    if(this->getWidth(this->ui->lblNick) > this->ui->lblNick->width()){
        chatBox *pr = qobject_cast<chatBox*>(parent);
        this->setUserWidth(this->getWidth(this->ui->lblNick)+8);
        pr->setAllUserNameSize(this->getWidth(this->ui->lblNick)+8);
    }
    this->calculateMessageWidth();
}

void chatEntry::calculateMessageWidth(){
    this->ui->lblChat->setGeometry(this->ui->lblNick->width() + 8 +
                                   this->ui->lblTime->width() + 8,0,
                                   this->width() -
                                   this->ui->lblNick->width() - 8 -
                                   this->ui->lblTime->width() - 8,
                                   16);

    int lines = ceil((double)this->getWidth(this->ui->lblChat) /
                     (double)this->ui->lblChat->width());

    this->setMinimumHeight(lines * 20);
    this->ui->lblChat->setMinimumHeight(this->minimumHeight() + 4);
}

int chatEntry::getWidth(QLabel *l) const{
    return l->fontMetrics().width(l->text());
}

chatEntry::~chatEntry(){
    delete ui;
}

void chatEntry::setUserWidth(int newWidth){
    this->ui->lblNick->setMinimumWidth(newWidth);
    this->ui->lblNick->setMaximumWidth(newWidth+2);

    this->calculateMessageWidth();
}

void chatEntry::resizeEvent(QResizeEvent *event){
    this->calculateMessageWidth();
}
