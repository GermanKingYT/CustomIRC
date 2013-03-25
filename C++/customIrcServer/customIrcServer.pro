#-------------------------------------------------
#
# Project created by QtCreator 2013-03-06T13:26:55
#
#-------------------------------------------------

QT       += core
QT		 += network

QT       -= gui

TARGET = customIrcServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS = -Wno-switch

SOURCES += main.cpp \
    ircclient.cpp \
    functions.cpp \
    mainapp.cpp \
    ircuser.cpp \
    clslog.cpp \
    uiclient.cpp \
    uiserver.cpp \
    jsoncommand.cpp \
    json.cpp \
    ../resources/jsoncommand.cpp \
    ../resources/json.cpp \
    ../resources/clslog.cpp

HEADERS += \
    ircclient.h \
    functions.h \
    mainapp.h \
    ircCodes.h \
    ircuser.h \
    clslog.h \
    uiclient.h \
    uiserver.h \
    jsoncommand.h \
    json.h \
    ../resources/jsoncommand.h \
    ../resources/json.h \
    ../resources/clslog.h


