#include <QApplication>
#include <QMainWindow>

#include <QObject>
#include <QDesktopWidget>

#include "console.h"
#include "newman.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow w;
    w.setWindowTitle("Central Park Control Console");

    Console console;

    w.setCentralWidget(&console);

    Newman newman;

    QObject::connect( &console, SIGNAL(StartHackerCrap()), &newman, SLOT(PlayAnimation()) );

    w.showFullScreen();
    //w.show();
    //newman.showFullScreen();
    newman.show();
    console.Begin();

    return a.exec();
}
