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
    chatEntry *tE = new chatEntry(user,message,this);
    this->entries.append(tE);
    this->ui->verticalLayout->addWidget(tE);

    QScrollArea *pr = (QScrollArea*)this->parentWidget();
    pr->scroll(0,0-tE->height());
}

void chatBox::setAllUserNameSize(int newSize){
    foreach (chatEntry *ce, this->entries) {
        ce->setUserWidth(newSize);
    }
}
