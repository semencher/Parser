#include "syntacticalanalysis.h"

SyntacticalAnalysis::SyntacticalAnalysis()
{
    current_ =  0;
    state_ =    NORMAL_WORK;

    ElementL2 elementL2;
    elementL2.isTerminal =  false;
    elementL2.sym =         "S";
    L2_.push(elementL2);
}

void SyntacticalAnalysis::clear()
{
    L1_ = std::stack<ElementL1>();
    L2_ = std::stack<ElementL2>();

    ElementL2 elementL2;
    elementL2.isTerminal =  false;
    elementL2.sym =         "S";
    L2_.push(elementL2);

    current_ =  0;
    state_ =    NORMAL_WORK;

    conclusion_ = std::stack<int>();
}

std::stack<ElementL1> SyntacticalAnalysis::stackL1() const
{
    return L1_;
}

std::stack<ElementL2> SyntacticalAnalysis::stackL2() const
{
    return L2_;
}

QVector<Descriptor> SyntacticalAnalysis::convolution() const
{
    return convolution_;
}

QVector<QString> SyntacticalAnalysis::serviceWords() const
{
    return serviceWords_;
}

QVector<QString> SyntacticalAnalysis::rightSigns() const
{
    return rightSigns_;
}

QVector<QString> SyntacticalAnalysis::identifiers() const
{
    return identifiers_;
}

QVector<QString> SyntacticalAnalysis::constsTable() const
{
    return constsTable_;
}

Grammar SyntacticalAnalysis::grammar() const
{
    return grammar_;
}

std::stack<int> SyntacticalAnalysis::conclusion() const
{
    return conclusion_;
}

void SyntacticalAnalysis::setConvolution(const QVector<Descriptor> & convolution)
{
    convolution_ = convolution;
}

void SyntacticalAnalysis::setServiceWords(const QVector<QString> & serviceWords)
{
    serviceWords_ = serviceWords;
}

void SyntacticalAnalysis::setRightSigns(const QVector<QString> & rightSigns)
{
    rightSigns_ = rightSigns;
}

void SyntacticalAnalysis::setIdentifiers(const QVector<QString> & identifiers)
{
    identifiers_ = identifiers;
}

void SyntacticalAnalysis::setConstsTable(const QVector<QString> & constsTable)
{
    constsTable_ = constsTable;
}

void SyntacticalAnalysis::setGrammar(const Grammar & grammar)
{
    grammar_ = grammar;
}
