QT       += core gui network webkit

# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

DEFINES += ANDROID

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

SOURCES += main.cpp mainwindow.cpp \
    chatnotification.cpp \
    chatinput.cpp \
    chatentry.cpp \
    chatbox.cpp \
    ../resources/jsoncommand.cpp \
    ../resources/json.cpp \
    ../resources/clslog.cpp \
    ../resources/clsevent.cpp \
    ircuser.cpp \
    clssettings.cpp \
    clsserverconn.cpp
HEADERS += mainwindow.h \
    chatnotification.h \
    chatinput.h \
    chatentry.h \
    chatbox.h \
    ../resources/jsoncommand.h \
    ../resources/json.h \
    ../resources/clslog.h \
    ../resources/clsevent.h \
    ircuser.h \
    clssettings.h \
    clsserverconn.h
FORMS += android/mainwindow.ui \
    android/chatnotification.ui \
    android/chatentry.ui \
    android/chatbox.ui

# Please do not modify the following two lines. Required for deployment.
include(android/deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    android/android/AndroidManifest.xml \
    android/android/res/drawable/icon.png \
    android/android/res/drawable/logo.png \
    android/android/res/drawable-hdpi/icon.png \
    android/android/res/drawable-ldpi/icon.png \
    android/android/res/drawable-mdpi/icon.png \
    android/android/res/layousplash.xml \
    android/android/res/values/libs.xml \
    android/android/res/values/strings.xml \
    android/android/res/values-de/strings.xml \
    android/android/res/values-el/strings.xml \
    android/android/res/values-es/strings.xml \
    android/android/res/values-estrings.xml \
    android/android/res/values-fa/strings.xml \
    android/android/res/values-fr/strings.xml \
    android/android/res/values-id/strings.xml \
    android/android/res/values-istrings.xml \
    android/android/res/values-ja/strings.xml \
    android/android/res/values-ms/strings.xml \
    android/android/res/values-nb/strings.xml \
    android/android/res/values-nl/strings.xml \
    android/android/res/values-pl/strings.xml \
    android/android/res/values-pt-rBR/strings.xml \
    android/android/res/values-ro/strings.xml \
    android/android/res/values-rs/strings.xml \
    android/android/res/values-ru/strings.xml \
    android/android/res/values-zh-rCN/strings.xml \
    android/android/res/values-zh-rTW/strings.xml \
    android/android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/android/src/org/kde/necessitas/origo/QtActivity.java \
    android/android/src/org/kde/necessitas/origo/QtApplication.java \
    android/android/version.xml \
    android/res/layousplash.xml \
    android/res/values/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-estrings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-istrings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/version.xml \
    android/AndroidManifest.xml \
    android/res/drawable/icon.png \
    android/res/drawable/logo.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/values/libs.xml
