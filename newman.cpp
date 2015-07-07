#include "newman.h"
#include <QLabel>
#include <QMovie>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

Newman::Newman(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("YOU DIDN'T SAY THE MAGIC WORD");

    if(QApplication::desktop()->numScreens() > 1){
        setGeometry(QApplication::desktop()->availableGeometry(0));
        qDebug() << Q_FUNC_INFO << this->size();
    }

    QPixmap bkgnd(":/backgrounds/jurassic-park-screen-1920x1440.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    QLabel *lbl = new QLabel();
    gif = new QMovie(":/animations/ahahah.gif");
    lbl->setPalette(palette);
    lbl->setMovie(gif);

    setCentralWidget(lbl);

}

void Newman::PlayAnimation(){
    gif->start();
}

