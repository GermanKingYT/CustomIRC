#include "chatnotification.h"
#include "ui_chatnotification.h"
#include <math.h>
#include "../resources/clslog.h"

chatNotification::chatNotification(QString message, QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::chatNotification)
    ,message(message)
    ,timeOfMessage(QTime::currentTime())
{
    ui->setupUi(this);
    this->setMinimumWidth(parent->width());
    clsLog(LOGTAGS_UI) << this->timeOfMessage.toString();

    this->ui->lblTime->setText(this->timeOfMessage.toString());

    this->ui->lblNotification->setText(this->message);

    this->calculateMessageWidth();
}

chatNotification::~chatNotification()
{
    delete ui;
}

void chatNotification::calculateMessageWidth(){
    this->ui->lblNotification->setGeometry(this->ui->lblTime->width() + 8,0,
                                   this->width() -
                                   this->ui->lblTime->width() - 8,
                                   16);

    int lines = ceil((double)this->getWidth(this->ui->lblNotification) /
                     (double)this->ui->lblNotification->width());

    this->setMinimumHeight(lines * 20);
    this->ui->lblNotification->setMinimumHeight(this->minimumHeight() + 4);
}

int chatNotification::getWidth(QLabel *l) const{
    return l->fontMetrics().width(l->text());
}


void chatNotification::resizeEvent(QResizeEvent *event){
    this->calculateMessageWidth();
}
