#include "console.h"
#include <QTimer>
#include <QScrollBar>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QDesktopWidget>

Console::Console(QWidget *parent) : QTextEdit()
{
    //private initializations
    lineCounter = 0;
    inputLine = "";

    //setup the widget if possible to the right screen
    if( QApplication::desktop()->numScreens() > 1){
        setGeometry(QApplication::desktop()->availableGeometry(1));
        qDebug() << Q_FUNC_INFO << this->size();
    }

    setTextColor(QColor(255,255,255));
    setFont(QFont("Terminal", 14));

    QPalette p = palette();
    p.setColor(QPalette::Base, QColor(0, 0, 230).light());
    setPalette(p);

    //autoscroll the textbox
    sBar = this->verticalScrollBar();
    sBar->setValue(sBar->maximum());

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(InsertText()) );
}

void Console::Begin(){
    //timer->start(800);

    //registers the callback keyPressEvent()
    insertPlainText(prompt);
    this->grabKeyboard();
}

//callback
void Console::keyPressEvent(QKeyEvent *e){

    if(e->key() == Qt::Key_Return ){
        qDebug() << "return key pressed" << inputLine;
        //do something with inputLine and reset it
        handleInputLine();
        insertPlainText(prompt);
        inputLine = "";
    }
    else{
        insertPlainText(e->text());
        inputLine.append(e->text());
    }

}

//parse input text
void Console::handleInputLine(){
    if( inputLine.compare("exit", Qt::CaseInsensitive) ==0 )
        QApplication::exit(0);

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
