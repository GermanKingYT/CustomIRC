/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatBox
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *chatBox)
    {
        if (chatBox->objectName().isEmpty())
            chatBox->setObjectName(QStringLiteral("chatBox"));
        chatBox->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatBox->sizePolicy().hasHeightForWidth());
        chatBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(chatBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(chatBox);

        QMetaObject::connectSlotsByName(chatBox);
    } // setupUi

    void retranslateUi(QWidget *chatBox)
    {
        chatBox->setWindowTitle(QApplication::translate("chatBox", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class chatBox: public Ui_chatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
