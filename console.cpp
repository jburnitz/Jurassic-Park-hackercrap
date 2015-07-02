#include "console.h"
#include <QTimer>
#include <QScrollBar>

Console::Console(QWidget *parent) : QTextEdit()
{



    setTextColor(QColor(255,255,255));
    setFont(QFont("Terminal", 14));

    QPalette p = palette();
    p.setColor(QPalette::Base, QColor(0, 0, 230).light());
    setPalette(p);

    sBar = this->verticalScrollBar();
    sBar->setValue(sBar->maximum());

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(InsertText()) );
    lineCounter = 0;
}

void Console::Begin(){
    timer->start(800);
}

void Console::InsertText(){

    insertPlainText(lines[lineCounter]);

    if(lineCounter==3){
        timer->setInterval(140);
    }

    if(lineCounter<67)
        lineCounter++;

    //set the newman bomb to go off in a second
    if (lineCounter == 66)
        QTimer::singleShot(1000, this, SLOT(fireEvents()) );


    //this scrolls the console
    sBar->setValue(sBar->maximum());
}

void Console::fireEvents(){
    emit( StartHackerCrap() );
}
