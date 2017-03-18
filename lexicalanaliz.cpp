#include "lexicalanaliz.h"

QVector<QString> LexicalAnaliz::serviceWords()
{
    return serviceWords_;
}

QVector<QString> LexicalAnaliz::rightSigns()
{
    return rightSigns_;
}

QVector<Descriptor> LexicalAnaliz::convolution()
{
    return convolution_;
}

QVector<QString> LexicalAnaliz::identifiers()
{
    return identifiers_;
}

QVector<QString> LexicalAnaliz::constsTable()
{
    return constsTable_;
}

void LexicalAnaliz::setServiceWords(const QVector<QString> & serviceWords)
{
    serviceWords_ = serviceWords;
    scaner_.setServiceWords(serviceWords);
}

void LexicalAnaliz::setRightSigns(const QVector<QString> & rightSigns)
{
    rightSigns_ = rightSigns;
    scaner_.setRightSigns(rightSigns);
}

bool LexicalAnaliz::serviceWordsIsEmpty()
{
    if (serviceWords_.isEmpty())
        return true;
    else
        return false;
}

bool LexicalAnaliz::rightSignsIsEmpty()
{
    if (rightSigns_.isEmpty())
        return true;
    else
        return false;
}

bool LexicalAnaliz::convolutionIsEmpty()
{
    if (convolution_.isEmpty())
        return true;
    else
        return false;
}

bool LexicalAnaliz::identifiersIsEmpty()
{
    if (identifiers_.isEmpty())
        return true;
    else
        return false;
}

bool LexicalAnaliz::constsTableIsEmpty()
{
    if (constsTable_.isEmpty())
        return true;
    else
        return false;
}

void LexicalAnaliz::clear()
{
    serviceWords_.clear();
    rightSigns_.clear();
    convolution_.clear();
    identifiers_.clear();
    constsTable_.clear();
    scaner_ = Scaner();
}

LexicalAnaliz::LexicalAnaliz(const QString & nameFile) : scaner_(nameFile)
{
}

LexicalAnaliz::LexicalAnaliz(const QByteArray & byteArray) : scaner_(byteArray)
{
}

bool LexicalAnaliz::setNameFile(const QString & nameFile)
{
    return scaner_.setNameFile(nameFile);
}

void LexicalAnaliz::setByteArray(const QByteArray & byteArray) :
{
    scaner_.setByteArray(byteArray);
}

void LexicalAnaliz::setContent(const QString & string)
{
    scaner_.setContent(string);
}

bool LexicalAnaliz::isSetProgram()
{
    return scaner_.isSetProgram();
}

QByteArray LexicalAnaliz::program()
{
    return scaner_.program();
}

bool LexicalAnaliz::run()
{
    bool defineInput = false;
    Lexem lexem;
    lexem = scaner.next();
    while (lexem.word != "") {
        if (lexem.type == Identifier) {
            if (defineInput) {
                if (identifiers_.contains(lexem.word)) {
                    qDebug() << "The variable " << lexem.word << " was defined above!";
                    convolution_.clear();
                    identifiers_.clear();
                    constsTable_.clear();
                    scaner_ = Scaner();
                    scaner_.setServiceWords(serviceWords_);
                    scaner_.setRightSigns(rightSigns_);
                    scaner_.setContent(QString());
                    return false;
                } else {
                    Descriptor descriptor;
                    descriptor.typeLexem = Identifier;
                    identifiers_.push_back(lexem.word);
                    descriptor.address = identifiers_.size() - 1;
                    convolution_.push_back(descriptor);
                }
            } else {
                if (identifiers_.contains(lexem.word)) {
                    Descriptor descriptor;
                    descriptor.typeLexem = Identifier;
                    identifiers_.push_back(lexem.word);
                    descriptor.address = identifiers_.size() - 1;
                    convolution_.push_back(descriptor);
                } else {
                    qDebug() << "The variable " << lexem.word << " is not defined!";
                    convolution_.clear();
                    identifiers_.clear();
                    constsTable_.clear();
                    scaner_ = Scaner();
                    scaner_.setServiceWords(serviceWords_);
                    scaner_.setRightSigns(rightSigns_);
                    scaner_.setContent(QString());
                    return false;
                }
            }
        }
        if (lexem.type == IntegerConst) {
            Descriptor descriptor;
            descriptor.typeLexem = IntegerConst;
            constsTable_.push_back(lexem.word);
            descriptor.address = constsTable_.size() - 1;
            convolution_.push_back(descriptor);
        }
        if (lexem.type == RightSignL) {
            if (lexem.word == ";")
                defineInput = false;
            Descriptor descriptor;
            descriptor.typeLexem = RightSignL;
            descriptor.address = rightSigns_.indexOf(lexem.word);
            convolution_.push_back(descriptor);
        }
        if (lexem.type == ServiceWord) {
            if (lexem.type == "int")
                defineInput = true;
            Descriptor descriptor;
            descriptor.typeLexem = ServiceWord;
            descriptor.address = serviceWords_.indexOf(lexem.word);
            convolution_.push_back(descriptor);
        }
        if (lexem.type == ErrorLexem) {
            qDebug() << "Error of lexical analiz: " << lexem.word;
            convolution_.clear();
            identifiers_.clear();
            constsTable_.clear();
            scaner_ = Scaner();
            scaner_.setServiceWords(serviceWords_);
            scaner_.setRightSigns(rightSigns_);
            scaner_.setContent(QString());
            return false;
        }
        lexem = scaner.next();
    }
    return true;
}

void LexicalAnaliz::showConvolution()
{
    auto iter = convolution_.begin();
    auto end = convolution_.end();
    Descriptor descriptor;
    descriptor = *iter;
    while (iter != end) {
        qDebug() << descriptor.typeLexem;
        qDebug() << descriptor.address;
        if (lexem.type == Identifier) {
            qDebug() << identifiers_[descriptor.address];
        }
        if (lexem.type == IntegerConst) {
            qDebug() << constsTable_[descriptor.address];
        }
        if (lexem.type == RightSignL) {
            qDebug() << rightSigns_[descriptor.address];
        }
        if (lexem.type == ServiceWord) {
            qDebug() << serviceWords_[descriptor.address];
        }
        qDebug() << "\n";
        ++iter;
    }
}

void LexicalAnaliz::showIdentifiers()
{
    qDebug() << "Table of identifiers:";
    int size = identifiers_.size();
    for (int i = 0; i < size; ++i) {
        qDebug() << i << "          " << identifiers_[i];
    }
    qDebug << "";
}

void LexicalAnaliz::showConstsTable()
{
    qDebug() << "Table of integer consts:";
    int size = constsTable_.size();
    for (int i = 0; i < size; ++i) {
        qDebug() << i << "          " << constsTable_[i];
    }
    qDebug << "";
}
