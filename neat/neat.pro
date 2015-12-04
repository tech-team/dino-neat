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

unix {
    DEFINES += PLATFORM_UNIX
    INCLUDEPATH += ../

    LIBS += -L"/home/igor/Projects/cpp/dino-neat/build-dino-Desktop_Qt_5_4_2_GCC_64bit-Debug/"
    LIBS += -ldino

    LIBS += -lsfml-audio
    LIBS += -lsfml-network
    LIBS += -lsfml-graphics
    LIBS += -lsfml-window
    LIBS += -lsfml-system
}

win32 {
    DEFINES += _WINDOWS

    INCLUDEPATH += ../
    INCLUDEPATH += ../dino/third_party/SFML/include

    LIBS += -L"C:/Projects/Qt/dino-neat/build-dino-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/"
    LIBS += -L"C:/Projects/dino-neat/build-dino-Desktop_Qt_5_5_1_MinGW_32bit-Debug/debug/"
    LIBS += -ldino

    LIBS += -L"C:/Projects/Qt/dino-neat/dino/third_party/SFML/lib/"
    LIBS += -L"C:/Projects/dino-neat/dino/third_party/SFML/lib/"

    LIBS += libFLAC
    LIBS += libfreetype
    LIBS += libjpeg
    LIBS += libogg
    LIBS += libopenal32
    LIBS += libvorbis
    LIBS += libvorbisenc
    LIBS += libvorbisfile


    LIBS += libsfml-audio
    LIBS += libsfml-network
    LIBS += libsfml-main
    LIBS += libsfml-graphics
    LIBS += libsfml-window
    LIBS += libsfml-system
}
