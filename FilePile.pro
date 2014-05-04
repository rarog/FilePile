#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T20:47:49
#
# FilePile - Remote SSH file manager
# Copyright (C) 2014  Andrej Sinicyn
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FilePile
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutform.cpp \
    sqlhelper.cpp \
    libs/botan/botan.cpp \
    libs/ssh/sshcapabilities.cpp \
    libs/ssh/sshchannel.cpp \
    libs/ssh/sshchannelmanager.cpp \
    libs/ssh/sshconnection.cpp \
    libs/ssh/sshconnectionmanager.cpp \
    libs/ssh/sshcryptofacility.cpp \
    libs/ssh/sshdirecttcpiptunnel.cpp \
    libs/ssh/sshincomingpacket.cpp \
    libs/ssh/sshinit.cpp \
    libs/ssh/sshkeyexchange.cpp \
    libs/ssh/sshkeygenerator.cpp \
    libs/ssh/sshkeypasswordretriever.cpp \
    libs/ssh/sshoutgoingpacket.cpp \
    libs/ssh/sshpacket.cpp \
    libs/ssh/sshpacketparser.cpp \
    libs/ssh/sshremoteprocess.cpp \
    libs/ssh/sshremoteprocessrunner.cpp \
    libs/ssh/sshsendfacility.cpp \
    libs/ssh/sftpchannel.cpp \
    libs/ssh/sftpdefs.cpp \
    libs/ssh/sftpfilesystemmodel.cpp \
    libs/ssh/sftpincomingpacket.cpp \
    libs/ssh/sftpoperation.cpp \
    libs/ssh/sftpoutgoingpacket.cpp \
    libs/ssh/sftppacket.cpp

HEADERS  += mainwindow.h \
    aboutform.h \
    sqlhelper.h \
    common.h \
    libs/botan/botan.h \
    libs/ssh/sshbotanconversions_p.h \
    libs/ssh/sshcapabilities_p.h \
    libs/ssh/sshchannel_p.h \
    libs/ssh/sshchannelmanager_p.h \
    libs/ssh/sshconnection_p.h \
    libs/ssh/sshconnection.h \
    libs/ssh/sshconnectionmanager.h \
    libs/ssh/sshcryptofacility_p.h \
    libs/ssh/sshdirecttcpiptunnel_p.h \
    libs/ssh/sshdirecttcpiptunnel.h \
    libs/ssh/ssherrors.h \
    libs/ssh/sshexception_p.h \
    libs/ssh/sshincomingpacket_p.h \
    libs/ssh/sshinit_p.h \
    libs/ssh/sshkeyexchange_p.h \
    libs/ssh/sshkeygenerator.h \
    libs/ssh/sshkeypasswordretriever_p.h \
    libs/ssh/sshoutgoingpacket_p.h \
    libs/ssh/sshpacket_p.h \
    libs/ssh/sshpacketparser_p.h \
    libs/ssh/sshpseudoterminal.h \
    libs/ssh/sshremoteprocess_p.h \
    libs/ssh/sshremoteprocess.h \
    libs/ssh/sshremoteprocessrunner.h \
    libs/ssh/sshsendfacility_p.h \
    libs/ssh/sftpchannel_p.h \
    libs/ssh/sftpchannel.h \
    libs/ssh/sftpdefs.h \
    libs/ssh/sftpfilesystemmodel.h \
    libs/ssh/sftpincomingpacket_p.h \
    libs/ssh/sftpoperation_p.h \
    libs/ssh/sftpoutgoingpacket_p.h \
    libs/ssh/sftppacket_p.h \
    libs/ssh/ssh_global.h

FORMS    += mainwindow.ui \
    aboutform.ui

INCLUDEPATH += libs

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

QT += sql
QT += network

TRANSLATIONS += translations/FilePile_de_DE.ts

RESOURCES += \
    res.qrc

