#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Loading translations.
    QTranslator translator;
    translator.load(":/translations/FilePile_" + QLocale::system().name() + ".qm");
    a.installTranslator(&translator);

    // Loading main application window.
    MainWindow w;
    w.show();

    return a.exec();
}
