#include <QApplication>
#include <QMainWindow>

#include <QObject>
#include <QDesktopWidget>

#include "console.h"
#include "newman.h"
#include "runguard.h"

int main(int argc, char *argv[])
{
    RunGuard guard( "some_random_key" );
    if ( !guard.tryToRun() )
        return 0;

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
