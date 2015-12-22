#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QObject>
#include <QDesktopWidget>

#include "console.h"
#include "newman.h"
#include "runguard.h"

int main(int argc, char *argv[])
{
    /*
    RunGuard guard( "some_random_key" );
    if ( !guard.tryToRun() )
        return 0;
    */

    QApplication a(argc, argv);

    Console console;
    console.setWindowTitle("Central Park Control Console");

    //setup the widget if possible to the right screen
    if( QApplication::desktop()->numScreens() > 1){
        console.setGeometry(QApplication::desktop()->availableGeometry(1));
        qDebug() << Q_FUNC_INFO << console.size();
    }

	//the laughing Dennis nedry
    Newman newman;

    QObject::connect( &console, SIGNAL(StartHackerCrap()), &newman, SLOT(PlayAnimation()) );

    console.showFullScreen();
    newman.showFullScreen();

    console.Begin();

    return a.exec();
}
