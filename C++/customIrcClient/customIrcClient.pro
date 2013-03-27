#-------------------------------------------------
#
# Project created by QtCreator 2013-03-15T12:58:13
#
#-------------------------------------------------

QT       += core gui network webkit

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
    clsuserentry.cpp

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
    clsuserentry.h

FORMS    += mainwindow.ui \
    chatentry.ui \
    chatbox.ui \
    chatnotification.ui \
    clsuserentry.ui

RESOURCES +=
