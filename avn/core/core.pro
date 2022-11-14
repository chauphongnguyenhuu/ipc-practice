TEMPLATE = lib
CONFIG += staticlib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    basemqreceiver.cpp \
    baseproxy.cpp \
    employeeproxy.cpp

HEADERS += \
    include/core/basemqreceiver.h \
    include/core/baseproxy.h \
    include/core/data.h \
    include/core/defines.h \
    include/core/employeeproxy.h
