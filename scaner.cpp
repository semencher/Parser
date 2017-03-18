#include "scaner.h"

Scaner::Scaner()
{
    position_ = 0;
}

Scaner::Scaner(const QString & nameFile)
{
    position_ = 0;
    QFile file;
    file.setFileName(nameFile);
    if (file.open(QIODevice::ReadOnly)) {
        program_ = file.readAll();
    }
}

bool Scaner::setNameFile(const QString & nameFile)
{
    QFile file;
    file.setFileName(nameFile);
    if (file.open(QIODevice::ReadOnly)) {
        program_ = file.readAll();
        position_ = 0;
        return true;
    }
    return false;
}

bool Scaner::isSetProgram()
{
    if (!program_.isEmpty())
        return true;
    else
        return false;
}

void Scaner::setServiceWords(QVector<QString> serviceWords)
{
    serviceWords_ = serviceWords;
}

void Scaner::setRightSigns(QVector<QString> rightSigns)
{
    rightSigns_ = rightSigns;
}

TypeSymbol Scaner::defineSymbolClass(char sym)
{
    if ((sym >= 'a' && sym <= 'z') || sym == '_') {
        return Character;
    }
    if (sym >= '0' && sym <= '9') {
        return Numeral;
    }
    QString symStr;
    symStr= sym;
    if (rightSigns_.contains(symStr)) {
        return RightSignS;
    }
    return ErrorSymbol;
}

bool Scaner::isSeparator(char sym)
{
    if (sym == ' ' || sym == '\n' || sym == '\r' || sym == 9) {
        return true;
    }
    return false;
}

Lexem Scaner::next()
{
    Lexem lexem;
    int size = program_.size();
    if (position_ >= size) {
        return lexem;
    }
    char sym;
    sym = program_[position_];
    position_++;
    while(true) {
        if (isSeparator(sym)) {
            if (position_ < size) {
                sym = program_[position_];
                position_++;
            } else {
                return lexem;
            }
        } else {
            break;
        }
    }
    TypeSymbol typeSymbol = defineSymbolClass(sym);
    lexem.word.push_back(sym);
    if (typeSymbol == Character) {
        lexem.type = Identifier;
        sym = program_[position_];
        position_++;
        while(true) {
            if (isSeparator(sym)) {
                if (serviceWords_.contains(lexem.word)) {
                    lexem.type = ServiceWord;
                }
                return lexem;
            }
            typeSymbol = defineSymbolClass(sym);
            if (typeSymbol == Numeral || typeSymbol == Character) {
                lexem.word = lexem.word + sym;
                if (position_ >= size) {
                    if (serviceWords_.contains(lexem.word)) {
                        lexem.type = ServiceWord;
                    }
                    return lexem;
                }
                sym = program_[position_];
                position_++;
            } else {
                position_--;
                if (serviceWords_.contains(lexem.word)) {
                    lexem.type = ServiceWord;
                }
                return lexem;
            }
        }
    }
    if (typeSymbol == Numeral) {
        lexem.type = IntegerConst;
        sym = program_[position_];
        position_++;
        while(true) {
            if (isSeparator(sym)) {
                return lexem;
            }
            typeSymbol = defineSymbolClass(sym);
            if (typeSymbol == Numeral) {
                lexem.word = lexem.word + sym;
                if (position_ >= size) {
                    return lexem;
                }
                sym = program_[position_];
                position_++;
            } else {
                position_--;
                return lexem;
            }
        }
    }
    if (typeSymbol == RightSignS) {
        lexem.type = RightSignL;
        if (position_ >= size) {
            return lexem;
        }
        sym = program_[position_];
        position_++;
        if ((lexem.word == "=" && sym == '=') ||
                (lexem.word == ">" && sym == '=') ||
                (lexem.word == "<" && sym == '=') ||
                (lexem.word == "&" && sym == '&') ||
                (lexem.word == "|" && sym == '|') ||
                (lexem.word == "!" && sym == '=')) {
            lexem.word = lexem.word + sym;
        } else {
            position_--;
        }
    }
    if (typeSymbol == ErrorSymbol) {
        lexem.type = ErrorLexem;
    }
    return lexem;
}

Scaner::Scaner(const QByteArray & byteArray)
{
    position_ = 0;
    program_ = byteArray;
}

void Scaner::setByteArray(const QByteArray & byteArray)
{
    program_ = byteArray;
    position_ = 0;
}

void Scaner::setContent(const QString & string)
{
    position_ = 0;
    program_ = string.toUtf8();
}

QByteArray Scaner::program()
{
    return program_;
}

QVector<QString> Scaner::serviceWords()
{
    return serviceWords_;
}

QVector<QString> Scaner::rightSigns()
{
    return rightSigns_;
}
