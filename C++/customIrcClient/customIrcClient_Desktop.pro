#-------------------------------------------------
#
# Project created by QtCreator 2013-03-15T12:58:13
#
#-------------------------------------------------

QT       += core gui network webkit

!win32 {
	# To support for pkg-config
	CONFIG += link_pkgconfig
	PKGCONFIG += libnotify
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customIrcClient
TEMPLATE = app

DEFINES += DESKTOP

SOURCES += main.cpp\
        mainwindow.cpp \
    clsserverconn.cpp \
    chatentry.cpp \
    chatbox.cpp \
    ircuser.cpp \
    chatinput.cpp \
    ../resources/jsoncommand.cpp \
    ../resources/json.cpp \
    ../resources/clslog.cpp \
    chatnotification.cpp \
    desktop/clsuserlist.cpp \
    desktop/clsuserentry.cpp \
    desktop/clsnotify.cpp \
    ../resources/clsevent.cpp \
    clssettings.cpp

HEADERS  += mainwindow.h \
    clsserverconn.h \
    chatentry.h \
    chatbox.h \
    ircuser.h \
    chatinput.h \
    ../resources/jsoncommand.h \
    ../resources/json.h \
    ../resources/clslog.h \
    chatnotification.h \
    desktop/clsuserlist.h \
    desktop/clsuserentry.h \
    desktop/clsnotify.h \
    ../resources/clsevent.h \
    clssettings.h

FORMS    += desktop/mainwindow.ui \
    desktop/chatentry.ui \
    desktop/chatbox.ui \
    desktop/chatnotification.ui \
    desktop/clsuserentry.ui

RESOURCES +=
