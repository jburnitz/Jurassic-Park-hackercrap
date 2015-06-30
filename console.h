#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QTextEdit>
#include <QString>

class QTimer;
class QScrollBar;

class Console : public QTextEdit
{
    Q_OBJECT

public:
    explicit Console(QWidget *parent = 0);
    void Begin();

private:
    int lineCounter;
    QTimer *timer;
    QScrollBar *sBar;
private slots:
    void InsertText();

signals:
   StartHackerCrap();
};

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
