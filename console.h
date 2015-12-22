#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
//#include <QTextEdit>
#include <QString>
#include <QMainWindow>

class QTimer;
class QTextEdit;
class QScrollBar;
class QKeyEvent;
//class QMainWindow;

class Console : public QMainWindow
{
    Q_OBJECT

public:
    explicit Console(QWidget *parent = 0);
    void Begin();

private:
    int lineCounter;
    QTextEdit* textEditor;
    QTimer *timer;
    QScrollBar *sBar;
    QString inputLine;

    void handleInputLine();
    void keyPressEvent(QKeyEvent *e);

private slots:
    void InsertText();
    void fireEvents();

signals:
   void StartHackerCrap();
};

 const QString prompt = "\n>";
 const QString lines[] = { "Jurassic Park, Security System Interface\n",
                           "Version 4.0.5, Alpha E\n",
                           "Ready...\n>",

                           "a","c","c","e","s","s"," ",
                           "s","e","c","u","r","i","t","y",

                           "\naccess: PERMISSION DENIED.\n>",

                           "a","c","c","e","s","s"," ",
                           "s","e","c","u","r","i","t","y"," ",
                           "g","r","i","d",

                           "\naccess: PERMISSION DENIED.\n>",

                           "a","c","c","e","s","s"," ",
                           "m","a","i","n"," ",
                           "s","e","c","u","r","i","t","y"," ",
                           "g","r","i","d",

                           "\naccess: PERMISSION DENIED.",
                           "...and...\n",
                           "YOU DIDN'T SAY THE MAGIC WORD!\n"
                         };

#endif // CONSOLE_H
