#include "scaner.h"

Scaner::Scaner()
{
}

Scaner::Scaner(const QString & nameFile)
{
    file_.setFileName(nameFile);
    file_.open(QIODevice::ReadOnly);
}

bool Scaner::setNameFile(const QString & nameFile)
{
    if (file_.isOpen()) {
        file_.close();
    }
    file_.setFileName(nameFile);
    if (file_.open(QIODevice::ReadOnly)) {
        return true;
    }
    return false;
}

bool Scaner::isFile()
{
    if (file_.isOpen())
        return true;
    else
        return false;
}

void Scaner::closeFile()
{
    file_.close();
}

