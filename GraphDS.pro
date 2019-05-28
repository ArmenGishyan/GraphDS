TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        application.cpp \
        arguments.cpp \
        commandline.cpp \
        commands.cpp \
        commandspool.cpp \
        engine.cpp \
        graph.cpp \
        main.cpp

HEADERS += \
    application.h \
    arguments.h \
    commandline.h \
    commands.h \
    commandspool.h \
    engine.h \
    graph.h \
    graphnode.h \
    helperfunctions.h
