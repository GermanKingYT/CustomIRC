#include "clsuserlist.h"

clsUserList::clsUserList(QWidget *parent)
    :QWidget(parent)
{
    this->setupUi();
}

clsUserList::~clsUserList()
{
}

void clsUserList::addUser(ircUser *user){
    //TODO: Alphabetical order
    this->verticalLayout->removeItem(this->verticalSpacer);
    clsUserEntry *nE = new clsUserEntry(user, this);
    this->verticalLayout->addWidget(nE);
    this->users.append(nE);

    this->verticalLayout->addItem(this->verticalSpacer);
    this->setMinimumHeight(this->users.count() * nE->minimumHeight());
}

void clsUserList::setupUi(){
    if (this->objectName().isEmpty())
        this->setObjectName(QStringLiteral("clsUserList"));
    this->resize(400, 300);
    QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);
}
