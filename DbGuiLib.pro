QT += core gui widgets

PROJECT_ROOT = ../..

TARGET = dbgui

DEFINES += DBGUILIB_LIBRARY

SOURCES += ledindicator.cpp \
    matrix4x4widget.cpp \
    quaternionwidget.cpp \
    urlwidget.cpp \
    vector2dwidget.cpp \
    vector3dwidget.cpp \
    vector4dwidget.cpp \
    stringlistwidget.cpp \
    editorfactory.cpp

HEADERS += dbguilib_global.h \
           ledindicator.h \
    limitedspinbox.h \
    matrix4x4widget.h \
    quaternionwidget.h \
    urlwidget.h \
    vector2dwidget.h \
    vector3dwidget.h \
    vector4dwidget.h \
    stringlistwidget.h \
    editorfactory.h

FORMS += qstringlistwidget.ui

RESOURCES +=

TRANSLATIONS +=

include($${PROJECT_ROOT}/lib.pri)
