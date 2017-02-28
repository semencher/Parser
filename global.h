#pragma once

#include <QString>
#include <QVector>

enum TypeLexem
{
    Identifier,
    IntegerConst,
    RightSignL,
    ServiceWord,
    ErrorLexem
};

enum TypeSymbol
{
    Character,
    Numeral,
    RightSignS,
    ErrorSymbol
};

struct Lexem
{
    QString word;
    TypeLexem type;
};

class ErrorParser
{
    QString message_;
public:
    ErrorParser(QString message = "")
    {
        message_ = message;
    }
    void setMessage(const QString message)
    {
        message_ = message;
    }
    QString getError()
    {
        return message_;
    }
};
