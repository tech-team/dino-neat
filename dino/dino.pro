QT += core
QT -= gui

TARGET = dino
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    point.cpp \
    world_object.cpp \
    world.cpp \
    obstacle.cpp \
    player.cpp \
    game.cpp

HEADERS += \
    point.h \
    world_object.h \
    world.h \
    obstacle.h \
    player.h \
    game.h

