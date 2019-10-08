#-------------------------------------------------
#
# Project created by QtCreator 2019-06-12T05:44:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app

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
        component.cpp \
        componenttext.cpp \
        electricdrawitem.cpp \
        main.cpp \
        mainwindow.cpp \
        port.cpp \
        schem.cpp \
        schematic.cpp \
        wire.cpp \
        wiresegment.cpp

HEADERS += \
        component.h \
        componenttext.h \
        electricdrawitem.h \
        mainwindow.h \
        port.h \
        schem.h \
        schematic.h \
        wire.h \
        wiresegment.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
