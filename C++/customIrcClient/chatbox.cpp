#include "chatbox.h"
#include "ui_chatbox.h"

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
    chatEntry *tE = new chatEntry(user,message,this);
    this->entries.append(tE);
    this->ui->verticalLayout->addWidget(tE);
}

void chatBox::setAllUserNameSize(int newSize){
    foreach (chatEntry *ce, this->entries) {
        ce->setUserWidth(newSize);
    }
}
