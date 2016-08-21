#-------------------------------------------------
#
# Project created by QtCreator 2016-08-21T14:34:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IDCard
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

DISTFILES += \
    icon.rc

RC_FILE += \
    icon.rc
