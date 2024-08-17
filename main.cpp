#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/Translations/Tetris_" + QLocale::system().name()); //???
    QApplication::installTranslator(&translator);
    srand(time(0));
    MainWindow w;
    w.show();
    return a.exec();

}
