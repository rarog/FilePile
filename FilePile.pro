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
        mainwindow.cpp \
    aboutform.cpp \
    sqlhelper.cpp

HEADERS  += mainwindow.h \
    aboutform.h \
    sqlhelper.h \
    common.h

FORMS    += mainwindow.ui \
    aboutform.ui

CONFIG += c++11
CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml \
    res/filepile_512.png \
    res/filepile_256.png \
    res/filepile_72.png \
    res/filepile_48.png \
    res/filepile_36.png \
    translations/FilePile_de_DE.ts \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    sql/dbversion.ini \
    Doxyfile

QT +=sql

TRANSLATIONS +=  translations/FilePile_de_DE.ts

RESOURCES += \
    res.qrc

