#pragma once

#include <QFile>

#include "global.h"

class Scaner
{
    QFile file_;
public:
    Scaner();
    Scaner(const QString & nameFile);
    bool setNameFile(const QString & nameFile);
    bool isFile();
    void closeFile();

};
