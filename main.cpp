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
