#include <QApplication>
#include <QMainWindow>
#include <QDebug>
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

    //setup the widget if possible to the right screen
    if( QApplication::desktop()->numScreens() > 1){
        w.setGeometry(QApplication::desktop()->availableGeometry(1));
        qDebug() << Q_FUNC_INFO << w.size();
    }
    w.setCentralWidget(&console);

	//the laughing Dennis nedry
    Newman newman;

    QObject::connect( &console, SIGNAL(StartHackerCrap()), &newman, SLOT(PlayAnimation()) );

    w.showFullScreen();
    //w.show();
    newman.showFullScreen();
    //newman.show();
    console.Begin();

    return a.exec();
}
