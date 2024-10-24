#-------------------------------------------------
#
# Project created by QtCreator 2018-08-27T11:14:54
#
#-------------------------------------------------

QT       += core gui widgets bluetooth charts network

TARGET = nems
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    bleclient.cpp \
    deviceinfo.cpp \
        main.cpp \
        mainwindow.cpp \
    btclient.cpp \
    cplotchart.cpp \
    nmesautomaticsearch.cpp \
    nmesdualmp.cpp \
    nmespinmap.cpp \
    nmessearch.cpp \
    nmessensor.cpp

HEADERS += \
    bleclient.h \
    deviceinfo.h \
        mainwindow.h \
    btclient.h \
    cplotchart.h \
    nmesautomaticsearch.h \
    nmesdualmp.h \
    nmespinmap.h \
    nmessearch.h \
    nmessensor.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    android/AndroidManifest.xml \
#    android/gradle/wrapper/gradle-wrapper.jar \
#    android/gradlew \
#    android/res/values/libs.xml \
#    android/build.gradle \
#    android/gradle/wrapper/gradle-wrapper.properties \
#    android/gradlew.bat \
#    android/AndroidManifest.xml \
#    android/gradle/wrapper/gradle-wrapper.jar \
#    android/gradlew \
#    android/res/values/libs.xml \
#    android/build.gradle \
#    android/gradle/wrapper/gradle-wrapper.properties \
#    android/gradlew.bat

#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

RESOURCES += \
    images.qrc
