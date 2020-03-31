#-------------------------------------------------
#
# Project created by QtCreator 2014-01-07T15:05:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = andrcalc
TEMPLATE = app
RC_FILE = andcalc.rc


SOURCES += main.cpp\
    CAllWindows.cpp \
    cbuttonscheck.cpp \
    cchecks.cpp \
    ccommander.cpp \
    ccalc.cpp \
    cmemory.cpp \
    cbuttons.cpp \
    clabelchange.cpp \
    cinputcalculatedata.cpp \
    cnotebook.cpp

HEADERS  += \
    CAllWindows.h \
    cbuttonscheck.h \
    cchecks.h \
    ccommander.h \
    ccalc.h \
    cmemory.h \
    cbuttons.h \
    clabelchange.h \
    cinputcalculatedata.h \
    cnotebook.h

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \
    andcalc.rc

