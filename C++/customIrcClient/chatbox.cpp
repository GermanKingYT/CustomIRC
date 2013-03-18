#include "chatbox.h"
#include "ui_chatbox.h"

chatBox::chatBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatBox)
{
    ui->setupUi(this);
    //Parse some random entries:
    for(int i = 0; i < 30; i++){
        QString name = "Gebruiker ";
        this->ui->verticalLayout->addWidget(new chatEntry(name
                                                          ,QString("Chat berichtje "+i)));
    }
}

chatBox::~chatBox()
{
    delete ui;
}
