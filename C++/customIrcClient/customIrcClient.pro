#-------------------------------------------------
#
# Project created by QtCreator 2013-03-15T12:58:13
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customIrcClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clsserverconn.cpp \
    clslog.cpp \
    chatentry.cpp \
    chatbox.cpp

HEADERS  += mainwindow.h \
    clsserverconn.h \
    clslog.h \
    chatentry.h \
    chatbox.h

FORMS    += mainwindow.ui \
    chatentry.ui \
    chatbox.ui
