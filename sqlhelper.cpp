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

#include "sqlhelper.h"

/**
 * @brief Default constructor
 *
 * @param parent
 */
SQLHelper::SQLHelper(QObject *parent) :
    QObject(parent)
{
}

/**
 * @brief Checks presence of DB and updates it if needed.
 *
 * @return bool State, if DB is valid and up to date.
 */
bool SQLHelper::ensurePresenceOfCurrentDB()
{
    bool result = false;
    int dbMajor = 0;
    int dbMinor = 0;
    QFile sqlFile;

    // Getting current app DB version.
    QSettings settings(":/sql/dbversion.ini", QSettings::IniFormat);
    settings.beginGroup("DBVersion");
    int appMajor = settings.value("Major", QVariant(0)).toInt();
    int appMinor = settings.value("Minor", QVariant(0)).toInt();
    settings.endGroup();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if(db.isValid())
    {
        QString path;
#ifndef Q_OS_ANDROID
        path = QStandardPaths::writableLocation(QStandardPaths::DataLocation).append(QDir::separator());

        // Ensure that path exists
        QDir qDir;
        qDir.mkpath(path);
#endif
        path.append("settings.db");
        db.setDatabaseName(path);
        db.setConnectOptions("QSQLITE_BUSY_TIMEOUT");
        if (db.open())
        {
            QSqlQuery query("CREATE TABLE IF NOT EXISTS \"_dbversion\" (\"major\" INT, \"minor\" INT) WITHOUT ROWID;"
                            "SELECT \"major\", \"minor\" FROM \"_dbversion\";");
            if (query.next())
            {
                dbMajor = query.value(0).Int;
                dbMinor = query.value(1).Int;
            }

            if ((dbMajor == 0) && (dbMinor == 0))
            {
                // Fresh db initialization
                while (true)
                {
                    sqlFile.setFileName(QString(":/sql/%1.sql").arg(appMajor));
                    if (!sqlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                        appMajor--;
                        if (appMajor < 0)
                            break;
                    }
                }

                if (sqlFile.isOpen())
                {
                    QTextStream in(&sqlFile);
                    db.transaction();
                    if ((result = query.exec(in.readAll())))
                        db.commit();
                    else
                        db.rollback();

                }
            }
        }
    }

    if (!result)
    {
        QSqlDatabase::removeDatabase(db.connectionName());
    }

    return result;
}
