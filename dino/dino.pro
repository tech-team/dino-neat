QT -= gui

I_WANT_LIB = true

TARGET = dino

CONFIG += console
CONFIG -= app_bundle


SOURCES += world_object.cpp \
    world.cpp \
    obstacle.cpp \
    rectangular_obstacle.cpp \
    player.cpp \
    game.cpp \
    timer.cpp \
    world_rasterizer.cpp \
    rectangular_object.cpp \
    overlay.cpp \
    obstacle_patterns/obstacle_pattern.cpp \
    obstacle_patterns/triple_pattern.cpp \
    obstacle_patterns/obstacle_pattern_factory.cpp \
    obstacle_patterns/post_pattern.cpp

HEADERS += \
    world_object.h \
    world.h \
    obstacle.h \
    rectangular_obstacle.h \
    player.h \
    game.h \
    timer.h \
    world_rasterizer.h \
    rectangular_object.h \
    overlay.h \
    utils.h \
    obstacle_patterns/obstacle_pattern.h \
    obstacle_patterns/triple_pattern.h \
    exceptions/not_implemented_exception.h \
    obstacle_patterns/obstacle_pattern_factory.h \
    obstacle_patterns/post_pattern.h \
    platform.h

QMAKE_CXXFLAGS += -std=c++14


unix {
    message(Building for unix)

    DEFINES += PLATFORM_UNIX

    LIBS += -lsfml-audio
    LIBS += -lsfml-network
    LIBS += -lsfml-graphics
    LIBS += -lsfml-window
    LIBS += -lsfml-system

}

win32 {
    message(Building for win32)

    DEFINES += _WINDOWS

    INCLUDEPATH += ./third_party/SFML/include
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

equals(I_WANT_LIB, true) {
    message(Building dino library)
    TEMPLATE = lib
    CONFIG += staticlib
} else {
    message(Building dino app)
    TEMPLATE = app
    SOURCES += main.cpp
}

CONFIG(debug, debug|release) {
    DEFINES += _DEBUG
}
