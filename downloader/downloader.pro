QT       += core network testlib

QT       -= gui

TARGET = downloader
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    downloader.cpp

HEADERS += \
    downloader.h
