/********************************************************************************
** Form generated from reading UI file 'chatentry.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATENTRY_H
#define UI_CHATENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_chatEntry
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblTime;
    QLabel *lblNick;
    QLabel *lblChat;

    void setupUi(QFrame *chatEntry)
    {
        if (chatEntry->objectName().isEmpty())
            chatEntry->setObjectName(QStringLiteral("chatEntry"));
        chatEntry->resize(484, 22);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatEntry->sizePolicy().hasHeightForWidth());
        chatEntry->setSizePolicy(sizePolicy);
        chatEntry->setMinimumSize(QSize(0, 20));
        chatEntry->setMaximumSize(QSize(16777215, 16777215));
        chatEntry->setFrameShape(QFrame::NoFrame);
        chatEntry->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(chatEntry);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 0, 1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblTime = new QLabel(chatEntry);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblTime->sizePolicy().hasHeightForWidth());
        lblTime->setSizePolicy(sizePolicy1);
        lblTime->setMaximumSize(QSize(48, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        lblTime->setFont(font);
        lblTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(lblTime);

        lblNick = new QLabel(chatEntry);
        lblNick->setObjectName(QStringLiteral("lblNick"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblNick->sizePolicy().hasHeightForWidth());
        lblNick->setSizePolicy(sizePolicy2);
        lblNick->setMinimumSize(QSize(20, 16));
        lblNick->setMaximumSize(QSize(20, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setBold(true);
        font1.setWeight(75);
        lblNick->setFont(font1);
        lblNick->setFrameShape(QFrame::NoFrame);
        lblNick->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        lblNick->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(lblNick);

        lblChat = new QLabel(chatEntry);
        lblChat->setObjectName(QStringLiteral("lblChat"));
        sizePolicy.setHeightForWidth(lblChat->sizePolicy().hasHeightForWidth());
        lblChat->setSizePolicy(sizePolicy);
        lblChat->setMinimumSize(QSize(340, 52));
        lblChat->setFont(font);
        lblChat->setFrameShape(QFrame::NoFrame);
        lblChat->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblChat->setWordWrap(true);
        lblChat->setOpenExternalLinks(true);
        lblChat->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(lblChat);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(chatEntry);

        QMetaObject::connectSlotsByName(chatEntry);
    } // setupUi

    void retranslateUi(QFrame *chatEntry)
    {
        chatEntry->setWindowTitle(QApplication::translate("chatEntry", "Frame", 0));
        lblTime->setText(QApplication::translate("chatEntry", "00:00:00", 0));
        lblNick->setText(QApplication::translate("chatEntry", "User:", 0));
        lblChat->setText(QApplication::translate("chatEntry", "Chat message", 0));
    } // retranslateUi

};

namespace Ui {
    class chatEntry: public Ui_chatEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATENTRY_H
