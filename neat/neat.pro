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
    chromosome.cpp \
    util.cpp

HEADERS += \
    neuron.h \
    edge.h \
    genetic.h \
    net.h \
    chromosome.h \
    innovation_number_getter.h \
    util.h \
    neat_config.h

QMAKE_CXXFLAGS += -Wall -std=c++14
