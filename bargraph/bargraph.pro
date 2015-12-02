QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

TARGET = bargraph
TEMPLATE = app


SOURCES += main.cpp \
           dialog.cpp \
           bargraph.cpp

HEADERS  += dialog.h \
            bargraph.h
