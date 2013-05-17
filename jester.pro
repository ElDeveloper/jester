QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jester
TEMPLATE = app


SOURCES += main.cpp\
        JesterMainWindow.cpp\
        BiomTableModel.cpp

HEADERS  += JesterMainWindow.h\
         BiomTableModel.h
