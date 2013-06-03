QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jester
TEMPLATE = app


SOURCES += main.cpp\
        JesterMainWindow.cpp\
        BiomTableModel.cpp\
        BiomTable.cpp\
        jsoncpp.cpp

HEADERS  += JesterMainWindow.h\
         BiomTableModel.h\
         BiomTable.h\
         json/json.h
