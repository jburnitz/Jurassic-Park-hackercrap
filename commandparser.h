#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>

class QStringList;

class CommandParser
{
public:
    CommandParser();
    QStringList Parse(QStringList argv);

private:
    QString cd;
};

#endif // COMMANDPARSER_H
