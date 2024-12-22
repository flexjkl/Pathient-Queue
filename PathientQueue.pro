QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Pathient.cpp \
    appointwindow.cpp \
    insertwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    showwindow.cpp

HEADERS += \
    Pathient.h \
    appointwindow.h \
    insertwindow.h \
    mainwindow.h \
    showwindow.h

RESOURCES += icons.qrc

QXLSX_PARENTPATH=C:/QtLibraries/         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=C:/QtLibraries/QXlsx/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=C:/QtLibraries/QXlsx/source/  # current QXlsx source path is ./source/
include(C:/QtLibraries/QXlsx/QXlsx.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
