TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../core/include

LIBS += -L../core -lcore

SOURCES += \
        localstorage.cpp \
        main.cpp

RESOURCES +=

HEADERS += \
    defines.h \
    localstorage.h
