#pragma once

#include <QFile>

#include "global.h"

class Scaner
{
public:
    Scaner();
    Scaner(const QString & nameFile);
    bool setNameFile(const QString & nameFile);
    bool isFile();
    void closeFile();
    void setServiceWords(QVector<QString> serviceWords);
    void setRightSigns(QVector<char> rightSigns);
    Lexem & next();

private:
    TypeSymbol defineSymbolClass(char sym);

    QFile file_;
    QVector<QString> serviceWords_;
    QVector<char> rightSigns_;
};
