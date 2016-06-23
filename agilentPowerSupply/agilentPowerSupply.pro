#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T23:30:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = agilentPowerSupply
TEMPLATE = app


SOURCES += main.cpp\
        controllerwindow.cpp

HEADERS  += controllerwindow.h \
    visa.h \
    visatype.h

FORMS    += controllerwindow.ui

unix|win32: LIBS += -L$$PWD/lib/ -lvisa32

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/lib/visa32.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/lib/libvisa32.a
