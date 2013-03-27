#include "chatbox.h"
#include "ui_chatbox.h"
#include <QScrollArea>

chatBox::chatBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatBox)
{
    ui->setupUi(this);
}



chatBox::~chatBox()
{
    delete ui;
}

void chatBox::addChat(ircUser &user, QString message){
    content *myContent = new content;
    myContent->widget = new chatEntry(user,message,this);
    myContent->type = WIDGETTYPES_CHATENTRY;

    this->entries.append(myContent);
    this->ui->verticalLayout->addWidget(myContent->widget);
}

void chatBox::addMessage(QString &message){
    content *myContent = new content;
    myContent->widget = new chatNotification(message,this);
    myContent->type = WIDGETTYPES_NOTIFICATION;

    this->entries.append(myContent);
    this->ui->verticalLayout->addWidget(myContent->widget);
}

void chatBox::addMessage(const char *msg){
    QString newMsg(msg);
    this->addMessage(newMsg);
}

void chatBox::setAllUserNameSize(int newSize){
    foreach (content *ce, this->entries) {
        if(ce->type == WIDGETTYPES_CHATENTRY){
            chatEntry *myWidget = dynamic_cast<chatEntry*>(ce->widget);
            myWidget->setUserWidth(newSize);
        }
    }
}
