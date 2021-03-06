#include "console.h"
#include "commandparser.h"

#include <QTimer>
#include <QScrollBar>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QTextEdit>

Console::Console(QWidget *parent) : QMainWindow()
{
    parser = new CommandParser();
    lineCounter = 0;
    counter=0;
    inputLine = "";
    textEditor = new QTextEdit(this);

    textEditor->setTextColor(QColor(255,255,255));
    textEditor->setFont(QFont("Terminal", 14));

    QPalette p = textEditor->palette();
    p.setColor(QPalette::Base, QColor(0, 0, 230).light());
    textEditor->setPalette(p);

    //autoscroll the textbox
    sBar = textEditor->verticalScrollBar();
    sBar->setValue(sBar->maximum());

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(InsertText()) );

    //so we can track focus events
    this->setFocusPolicy(Qt::StrongFocus);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

void Console::Begin(){
    //timer->start(800);

    //registers the callback keyPressEvent()
    this->grabKeyboard();

    this->setCentralWidget(textEditor);
    textEditor->insertPlainText(lines[lineCounter++]);
    textEditor->insertPlainText(lines[lineCounter++]);
    textEditor->insertPlainText(lines[lineCounter++]);
}

void Console::focusOutEvent(QFocusEvent *e){
    qDebug() << "focused out!";
    if(e->reason() == Qt::ActiveWindowFocusReason){

    }
}

//keypress callback
void Console::keyPressEvent(QKeyEvent *e){

    if( e->key() == Qt::Key_Return ){
        qDebug() << "return key pressed" << inputLine;
        //do something with inputLine and reset it
        handleInputLine();
        textEditor->insertPlainText(prompt);
        inputLine = "";
    }
    else{
        textEditor->insertPlainText(e->text());
        inputLine.append(e->text());
    }

}

//parse input text
void Console::handleInputLine(){
    //timer->start(800);
    if( inputLine.compare("exit", Qt::CaseInsensitive) ==0 )
        QApplication::exit(0);
    else{
        QStringList ret = parser->Parse(inputLine.split(" "));
        foreach (QString str , ret){
            textEditor->insertPlainText("\n"+str);
        }
        //this scrolls the console
        sBar->setValue(sBar->maximum());
    }
    this->counter++;
    if(counter >= 3){
        lineCounter = 67;
        timer->start(500);
        QTimer::singleShot(1000, this, SLOT(fireEvents()) );
    }

}

void Console::InsertText(){
    textEditor->insertPlainText(lines[lineCounter]);

    if(lineCounter>=3){
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
