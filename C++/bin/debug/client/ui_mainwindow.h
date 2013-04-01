/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "chatbox.h"
#include "chatinput.h"
#include "clsuserlist.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    chatBox *chatbox;
    QStatusBar *statusBar;
    QDockWidget *userDock;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea_2;
    clsUserList *userList;
    QMenuBar *menuBar;
    QDockWidget *chatDock;
    QWidget *chatDock_Widget;
    QHBoxLayout *horizontalLayout_3;
    chatInput *mChatInput;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(602, 429);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        chatbox = new chatBox();
        chatbox->setObjectName(QStringLiteral("chatbox"));
        chatbox->setGeometry(QRect(0, 0, 429, 259));
        sizePolicy.setHeightForWidth(chatbox->sizePolicy().hasHeightForWidth());
        chatbox->setSizePolicy(sizePolicy);
        scrollArea->setWidget(chatbox);

        horizontalLayout_2->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        userDock = new QDockWidget(MainWindow);
        userDock->setObjectName(QStringLiteral("userDock"));
        userDock->setMinimumSize(QSize(148, 122));
        userDock->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        userDock->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea_2 = new QScrollArea(dockWidgetContents_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(130, 0));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setFrameShadow(QFrame::Plain);
        scrollArea_2->setLineWidth(0);
        scrollArea_2->setWidgetResizable(true);
        userList = new clsUserList();
        userList->setObjectName(QStringLiteral("userList"));
        userList->setGeometry(QRect(0, 0, 130, 240));
        scrollArea_2->setWidget(userList);

        horizontalLayout->addWidget(scrollArea_2);

        userDock->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), userDock);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 23));
        MainWindow->setMenuBar(menuBar);
        chatDock = new QDockWidget(MainWindow);
        chatDock->setObjectName(QStringLiteral("chatDock"));
        chatDock->setMaximumSize(QSize(524287, 100));
        chatDock->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        chatDock->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        chatDock_Widget = new QWidget();
        chatDock_Widget->setObjectName(QStringLiteral("chatDock_Widget"));
        horizontalLayout_3 = new QHBoxLayout(chatDock_Widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        mChatInput = new chatInput(chatDock_Widget);
        mChatInput->setObjectName(QStringLiteral("mChatInput"));
        mChatInput->setMinimumSize(QSize(0, 35));
        mChatInput->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mChatInput->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mChatInput->setLineWrapMode(QPlainTextEdit::NoWrap);

        horizontalLayout_3->addWidget(mChatInput);

        chatDock->setWidget(chatDock_Widget);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), chatDock);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "K-4U Chat", 0));
        userDock->setWindowTitle(QApplication::translate("MainWindow", "Users", 0));
        chatDock->setWindowTitle(QApplication::translate("MainWindow", "Chat", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
