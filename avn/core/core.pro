TEMPLATE = lib
CONFIG += staticlib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    employeeproxy.cpp

HEADERS += \
    include/core/data.h \
    include/core/defines.h \
    include/core/employeeproxy.h
