#include <QApplication>
#include <QMainWindow>
#include <QObject>


#include "console.h"
#include "newman.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow w;
    w.setWindowTitle("Central Park Control Console");

    Console *console = new Console();

    w.setGeometry(100,100,500,600);
    w.setCentralWidget(console);

    Newman *newman = new Newman();

    QObject::connect( console, SIGNAL(StartHackerCrap()), newman, SLOT(Start()));

    w.show();
    console->Begin();

    return a.exec();
}
