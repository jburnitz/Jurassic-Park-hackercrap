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

    Console *console = new Console();

    if(a.desktop()->numScreens() > 1){
        console->setGeometry(a.desktop()->availableGeometry(1));
    }

    w.setCentralWidget(console);

    Newman *newman = new Newman();

    QObject::connect( console, SIGNAL(StartHackerCrap()), newman, SLOT(Start()));

    w.showFullScreen();
    newman->showFullScreen();
    console->Begin();

    return a.exec();
}
