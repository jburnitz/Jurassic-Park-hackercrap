#include "commandparser.h"
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>

CommandParser::CommandParser()
{
}

QStringList CommandParser::Parse(QStringList argv){
    QStringList results;
    cd = QDir().currentPath();
    qDebug() << Q_FUNC_INFO << argv;

    if(argv.at(0) == "ls"){
        argv.pop_front();
        qDebug() << "exec ls";
        QDir entries;
        entries.setPath(cd);

        results = QStringList(entries.entryList());
        return results;
    }
    else if (argv.at(0) == "pwd"){
        qDebug() << "exec pwd";

        //since we're already in the current dir, return it!
        results.append(cd);

        return results;
    }
}
