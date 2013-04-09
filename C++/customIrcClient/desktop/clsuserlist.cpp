#include "clsuserlist.h"

namespace client{

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

        clsUserEntry *nE = new clsUserEntry(user);

        this->verticalLayout->addWidget(nE);
        this->users.insert(user,nE);

        this->verticalLayout->addItem(this->verticalSpacer);
        this->setMinimumHeight(this->users.count() * nE->minimumHeight());
    }

    void clsUserList::refreshUser(ircUser *user){
        this->users[user]->refresh();
    }

    void clsUserList::removeUser(ircUser *user){
        clsUserEntry *ourUser = this->users[user];
        delete this->users[user];
        //this->verticalLayout->removeWidget(ourUser);
		//this->users.remove(user);
	}

	void clsUserList::clear(){
		this->setupUi();
	}

    void clsUserList::setupUi(){
        if (this->objectName().isEmpty())
            this->setObjectName(QString("clsUserList"));
        this->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
        this->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(this);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);
    }
}
