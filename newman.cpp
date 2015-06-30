#include "newman.h"
#include <QLabel>
#include <QMovie>

Newman::Newman(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("YOU DIDN'T SAY THE MAGIC WORD");

    QLabel *lbl = new QLabel();
    gif = new QMovie("ahahah.gif");
    lbl->setMovie(gif);

    setCentralWidget(lbl);
}

void Newman::Start(){
    gif->start();
    this->show();
}

