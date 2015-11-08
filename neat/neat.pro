QT -= gui

TARGET = neat
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    neuron.cpp \
    edge.cpp \
    genetic.cpp \
    net.cpp \
    chromosome.cpp

HEADERS += \
    neuron.h \
    edge.h \
    genetic.h \
    net.h \
    chromosome.h

QMAKE_CXXFLAGS += -Wall -std=c++14
