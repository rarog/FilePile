/****************************************************************************
**
** FilePile - Remote SSH file manager
** Copyright (C) 2014  Andrej Sinicyn
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include "common.h"
#include "sqlhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Settomg global app info.
    QCoreApplication::setOrganizationName(AUTHOR);
    QCoreApplication::setOrganizationDomain(APP_DOMAIN);
    QCoreApplication::setApplicationName(APP_NAME);

    // Loading translations.
    QTranslator translator;
    translator.load(":/translations/FilePile_" + QLocale::system().name() + ".qm");
    a.installTranslator(&translator);

    // DB checking and updateing
    SQLHelper::ensurePresenceOfCurrentDB();

    // Loading main application window.
    MainWindow w;
    w.show();

    return a.exec();
}
