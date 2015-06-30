#include "console.h"
#include <QTimer>
#include <QScrollBar>

Console::Console(QWidget *parent) : QTextEdit()
{
    setTextColor(QColor(255,255,255));
    setFont(QFont("Terminal", 14));

    QPalette p = palette();
    p.setColor(QPalette::Base, QColor(0, 0, 200).light());
    setPalette(p);

    sBar = this->verticalScrollBar();
    sBar->setValue(sBar->maximum());

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(InsertText()) );
    lineCounter = 0;
}

void Console::Begin(){
    timer->start(500);
}

void Console::InsertText(){

    insertPlainText(lines[lineCounter]);

    if(lineCounter==2)
        timer->setInterval(100);

    if(lineCounter<67)
        lineCounter++;

    if (lineCounter == 66)
        emit( StartHackerCrap() );


    //this scrolls the console
    sBar->setValue(sBar->maximum());
}

