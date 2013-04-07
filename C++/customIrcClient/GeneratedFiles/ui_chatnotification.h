/********************************************************************************
** Form generated from reading UI file 'chatnotification.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATNOTIFICATION_H
#define UI_CHATNOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatNotification
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lblTime;
    QLabel *lblNotification;

    void setupUi(QWidget *chatNotification)
    {
        if (chatNotification->objectName().isEmpty())
            chatNotification->setObjectName(QStringLiteral("chatNotification"));
        chatNotification->resize(432, 20);
        chatNotification->setMinimumSize(QSize(0, 20));
        horizontalLayout = new QHBoxLayout(chatNotification);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        lblTime = new QLabel(chatNotification);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTime->sizePolicy().hasHeightForWidth());
        lblTime->setSizePolicy(sizePolicy);
        lblTime->setMaximumSize(QSize(48, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        lblTime->setFont(font);
        lblTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(lblTime);

        lblNotification = new QLabel(chatNotification);
        lblNotification->setObjectName(QStringLiteral("lblNotification"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblNotification->sizePolicy().hasHeightForWidth());
        lblNotification->setSizePolicy(sizePolicy1);
        lblNotification->setMinimumSize(QSize(340, 52));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setBold(true);
        font1.setWeight(75);
        lblNotification->setFont(font1);
        lblNotification->setFrameShape(QFrame::NoFrame);
        lblNotification->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblNotification->setWordWrap(true);
        lblNotification->setOpenExternalLinks(true);
        lblNotification->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(lblNotification);


        retranslateUi(chatNotification);

        QMetaObject::connectSlotsByName(chatNotification);
    } // setupUi

    void retranslateUi(QWidget *chatNotification)
    {
        chatNotification->setWindowTitle(QApplication::translate("chatNotification", "Form", 0));
        lblTime->setText(QApplication::translate("chatNotification", "00:00:00", 0));
        lblNotification->setText(QApplication::translate("chatNotification", "Notification", 0));
    } // retranslateUi

};

namespace Ui {
    class chatNotification: public Ui_chatNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATNOTIFICATION_H
