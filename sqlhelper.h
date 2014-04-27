#ifndef SQLHELPER_H
#define SQLHELPER_H

#include <QObject>
#include <QStandardPaths>
#include <QDir>
#include <QSettings>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>

class SQLHelper : public QObject
{
    Q_OBJECT
public:
    explicit SQLHelper(QObject *parent = 0);
    static bool ensurePresenceOfCurrentDB();

signals:

public slots:

};

#endif // SQLHELPER_H
