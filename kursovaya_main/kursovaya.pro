#-------------------------------------------------
#
# Project created by QtCreator 2019-10-05T17:52:11
#
#-------------------------------------------------

CONFIG += c++11
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kursovaya
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    register.cpp \
    games.cpp \
    sqlwork.cpp \
    leaders.cpp

HEADERS  += mainwindow.h \
    register.h \
    games.h \
    sqlwork.h \
    leaders.h

FORMS    += mainwindow.ui \
    register.ui \
    games.ui \
    leaders.ui

RESOURCES += \
    photo.qrc

