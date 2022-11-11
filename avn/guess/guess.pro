QT += quick

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

SOURCES += \
        employeecontroller.cpp \
        employeelistmodel.cpp \
        main.cpp

RESOURCES += qml.qrc

HEADERS += \
    employeecontroller.h \
    employeelistmodel.h
