QT += core
QT -= gui

CONFIG += c++11

TARGET = Parser
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    scaner.cpp

HEADERS += \
    scaner.h \
    global.h