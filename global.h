#pragma once

#include <QString>
#include <QVector>
#include <QPair>
// TODO: ChernyshovSV - Убрать после завершения отладки.
#include <QDebug>

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

struct Descriptor
{
    int address;
    TypeLexem typeLexem;
};

struct Grammar {
    // QPair: 1 - сколько всего альтернатив, 2 - индекс первой в массиве.
    QMap<QString, QPair<int, int>> infAlt;

    // TODO: ChernyshovSV - Проверить, нужна ли строчка ниже.
    QVector<QString> lPart;
    QVector<QVector<QString>> rPart;
};

enum ParserState {
    NORMAL_WORK,
    RETURN_STATE,
    DONE
};

struct ElementL1 {
    bool isTerminal;
    QString sym;
    int currentAlt;
    int countAlt;
};

struct ElementL2 {
    bool isTerminal;
    QString sym;
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
