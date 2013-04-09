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
#QMAKE_CXXFLAGS = -Wno-switch

SOURCES += main.cpp \
    ircclient.cpp \
    functions.cpp \
    mainapp.cpp \
    ircuser.cpp \
    uiclient.cpp \
    uiserver.cpp \
    ../resources/jsoncommand.cpp \
    ../resources/json.cpp \
    ../resources/clslog.cpp \
    clssettings.cpp \
    ../resources/clsevent.cpp \
    ../resources/events/eventchat.cpp \
    ../resources/events/eventuserjoin.cpp \
    ../resources/events/eventuserleave.cpp \
    ../resources/events/eventuserchangestatus.cpp \
    ../resources/events/eventuserchangenick.cpp \
    ../resources/events/eventservermessage.cpp

HEADERS += \
    ircclient.h \
    functions.h \
    mainapp.h \
    ircCodes.h \
    ircuser.h \
    uiclient.h \
    uiserver.h \
    ../resources/jsoncommand.h \
    ../resources/json.h \
    ../resources/clslog.h \
    clssettings.h \
    ../resources/clsevent.h \
    ../resources/events/eventchat.h \
    ../resources/events/events.h \
    ../resources/events/eventuserjoin.h \
    ../resources/events/eventuserleave.h \
    ../resources/events/eventuserchangestatus.h \
    ../resources/events/eventuserchangenick.h \
    ../resources/events/eventservermessage.h

OTHER_FILES +=


