#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T20:47:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FilePile
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml \
    res/filepile_512.png \
    res/filepile_256.png \
    res/filepile_72.png \
    res/filepile_48.png \
    res/filepile_36.png

RESOURCES += \
    res.qrc

