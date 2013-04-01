/********************************************************************************
** Form generated from reading UI file 'clsuserentry.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLSUSERENTRY_H
#define UI_CLSUSERENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clsUserEntry
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *lblGravatar;
    QLabel *lblUserName;
    QLabel *lblUserStatus;

    void setupUi(QWidget *clsUserEntry)
    {
        if (clsUserEntry->objectName().isEmpty())
            clsUserEntry->setObjectName(QStringLiteral("clsUserEntry"));
        clsUserEntry->resize(400, 34);
        clsUserEntry->setMinimumSize(QSize(0, 34));
        clsUserEntry->setMaximumSize(QSize(16777215, 34));
        horizontalLayout = new QHBoxLayout(clsUserEntry);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        lblGravatar = new QLabel(clsUserEntry);
        lblGravatar->setObjectName(QStringLiteral("lblGravatar"));
        lblGravatar->setMinimumSize(QSize(32, 32));
        lblGravatar->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(lblGravatar);

        lblUserName = new QLabel(clsUserEntry);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        lblUserName->setFont(font);

        horizontalLayout->addWidget(lblUserName);

        lblUserStatus = new QLabel(clsUserEntry);
        lblUserStatus->setObjectName(QStringLiteral("lblUserStatus"));
        lblUserStatus->setFont(font);
        lblUserStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblUserStatus);


        retranslateUi(clsUserEntry);

        QMetaObject::connectSlotsByName(clsUserEntry);
    } // setupUi

    void retranslateUi(QWidget *clsUserEntry)
    {
        clsUserEntry->setWindowTitle(QApplication::translate("clsUserEntry", "Form", 0));
        lblGravatar->setText(QString());
        lblUserName->setText(QApplication::translate("clsUserEntry", "user", 0));
        lblUserStatus->setText(QApplication::translate("clsUserEntry", "Online", 0));
    } // retranslateUi

};

namespace Ui {
    class clsUserEntry: public Ui_clsUserEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLSUSERENTRY_H
