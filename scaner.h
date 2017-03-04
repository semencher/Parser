#pragma once

#include <QFile>

#include "global.h"

class Scaner
{
public:
    Scaner();
    Scaner(const QString & nameFile);
    Scaner(const QByteArray & byteArray);
    bool setNameFile(const QString & nameFile);
    void setByteArray(const QByteArray & byteArray);
    void setContent(const QString & string);
    bool isSetProgram();
    void setServiceWords(QVector<QString> serviceWords);
    void setRightSigns(QVector<QString> rightSigns);
    Lexem next();
    QByteArray program();
    QVector<QString> serviceWords();
    QVector<QString> rightSigns();

private:
    TypeSymbol defineSymbolClass(char sym);
    bool isSeparator(char sym);

    int position_;
    QByteArray program_;
    QVector<QString> serviceWords_;
    QVector<QString> rightSigns_;
};
