#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T13:37:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    projectile.cpp \
    enemy.cpp

HEADERS  += \
    game.h \
    player.h \
    projectile.h \
    enemy.h

RESOURCES += \
    resources.qrc
