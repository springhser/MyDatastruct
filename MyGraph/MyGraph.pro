QT += core
QT -= gui

CONFIG += c++11

TARGET = MyGraph
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mygraph.cpp \
    node.cpp \
    edge.cpp

HEADERS += \
    mygraph.h \
    node.h \
    edge.h
