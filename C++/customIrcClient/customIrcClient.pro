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
    clsuserlist.cpp \
    clsuserentry.cpp \
    clsnotify.cpp \
    ../resources/clsevent.cpp

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
    clsuserlist.h \
    clsuserentry.h \
    clsnotify.h \
    ../resources/clsevent.h

FORMS    += mainwindow.ui \
    chatentry.ui \
    chatbox.ui \
    chatnotification.ui \
    clsuserentry.ui

RESOURCES +=
