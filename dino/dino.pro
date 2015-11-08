QT -= gui

TARGET = dino
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    world_object.cpp \
    world.cpp \
    obstacle.cpp \
    player.cpp \
    game.cpp \
    timer.cpp \
    world_rasterizer.cpp

HEADERS += \
    world_object.h \
    world.h \
    obstacle.h \
    player.h \
    game.h \
    timer.h \
    world_rasterizer.h

QMAKE_CXXFLAGS += -std=c++14 -O0

#DEFINES += SFML_STATIC

unix {
    DEFINES += PLATFORM_UNIX

    LIBS += -lsfml-audio
    LIBS += -lsfml-network
    LIBS += -lsfml-graphics
    LIBS += -lsfml-window
    LIBS += -lsfml-system

}

win32 {
    DEFINES += _WINDOWS
    DEFINES += WIN32_LEAN_AND_MEAN

    INCLUDEPATH += ./third_party/SFML/include
    LIBS += -L"C:/Projects/Qt/dino-neat/dino/third_party/SFML/lib/"

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

CONFIG(debug, debug|release) {
    DEFINES += _DEBUG
}
