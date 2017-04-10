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

void SyntacticalAnalysis::run()
{
    while(true) {
        if (state_ == NORMAL_WORK) {
            ElementL2 elementL2 = L2_.top();
            if (elementL2.isTerminal) {
                bool same = false;
                if (convolution_[current_].typeLexem == Identifier && elementL2.sym == "I") {
                    same = true;
                }
                if (convolution_[current_].typeLexem == IntegerConst && elementL2.sym == "C"){
                    same = true;
                }
                if (convolution_[current_].typeLexem == RightSignL &&
                        rightSigns_[convolution_[current_].address] == elementL2.sym) {
                    same = true;
                }
                if (convolution_[current_].typeLexem == ServiceWord &&
                        serviceWords_[convolution_[current_].address] == elementL2.sym) {
                    same = true;
                }
                if (!same) {
                    step4();
                    continue;
                } else {
                    step2();
                    if (current_ == convolution_.size()) {
                        if (L2_.empty()) {
                            step3();
                            break;
                        } else {
                            step3Else();
                            continue;
                        }
                    } else {
                        if (L2_.empty()) {
                            step3Else();
                            continue;
                        } else {
                            continue;
                        }
                    }
                }
            } else {
                step1();
                continue;
            }
        }
        if (state_ == RETURN_STATE) {
            ElementL1 elementL1 = L1_.top();
            if (elementL1.isTerminal) {
                step5();
                continue;
            } else {
                if (elementL1.countAlt > elementL1.currentAlt + 1) {
                    step6a();
                    continue;
                } else {
                    if (elementL1.sym == "S" && current_ == 0) {
                        step6b();
                    } else {
                        step6v();
                        continue;
                    }
                }
            }
        }
        if (state_ == DONE) {
            step3();
            break;
        }
    }
}

void SyntacticalAnalysis::step1()
{
    ElementL2 elementL2 = L2_.top();
    L2_.pop();
    ElementL1 elementL1;
    elementL1.sym =         elementL2.sym;
    elementL1.isTerminal =  false;
    elementL1.countAlt =    grammar_.infAlt[elementL1.sym].first;
    elementL1.currentAlt =  0;
    L1_.push(elementL1);
    QVector<QString> alt = grammar_.rPart[grammar_.infAlt[elementL1.sym].second];
    size_t size = alt.size();
    for (int i = size - 1; i >= 0; --i) {
        elementL2.sym = alt[i];
        if (grammar_.infAlt.contains(elementL2.sym)) {
            elementL2.isTerminal = false;
        } else {
            elementL2.isTerminal = true;
        }
        L2_.push(elementL2);
    }
}

void SyntacticalAnalysis::step2()
{
    ElementL2 elementL2 = L2_.top();
    L2_.pop();
    ElementL1 elementL1;
    elementL1.sym =         elementL2.sym;
    elementL1.isTerminal =  true;
    L1_.push(elementL1);
    current_++;
}

void SyntacticalAnalysis::step3()
{
    state_ = DONE;
    std::stack<ElementL1> tmp;
    while(!L1_.empty()) {
        ElementL1 elementL1 = L1_.top();
        tmp.push(elementL1);
        L1_.pop();
        if(!elementL1.isTerminal) {
            conclusion_.push(elementL1.currentAlt +
                             grammar_.infAlt[elementL1.sym].second);
        }
    }
    while(!tmp.empty()) {
        L1_.push(tmp.top());
        tmp.pop();
    }
}

void SyntacticalAnalysis::step3Else()
{
    state_ = RETURN_STATE;
}

void SyntacticalAnalysis::step4()
{
    state_ = RETURN_STATE;
}

void SyntacticalAnalysis::step5()
{
    current_--;
    ElementL1 elementL1 = L1_.top();
    L1_.pop();
    ElementL2 elementL2;
    elementL2.sym =         elementL1.sym;
    elementL2.isTerminal =  true;
    L2_.push(elementL2);
}

void SyntacticalAnalysis::step6a()
{
    state_ = NORMAL_WORK;
    ElementL1 elementL1 = L1_.top();
    L1_.pop();
    size_t sizeOfAlt = grammar_.rPart[grammar_.infAlt[elementL1.sym].second +
            elementL1.currentAlt].size();
    for (size_t i = 0; i < sizeOfAlt; ++i) {
        L2_.pop();
    }
    elementL1.currentAlt++;
    L1_.push(elementL1);

    QVector<QString> alt = grammar_.rPart[grammar_.infAlt[elementL1.sym].second +
            elementL1.currentAlt];
    size_t size = alt.size();
    for (int i = size - 1; i >= 0; --i) {
        ElementL2 elementL2;
        elementL2.sym = alt[i];
        if (grammar_.infAlt.contains(elementL2.sym)) {
            elementL2.isTerminal = false;
        } else {
            elementL2.isTerminal = true;
        }
        L2_.push(elementL2);
    }
}

void SyntacticalAnalysis::step6b()
{
    ErrorParser e("Left output is impossible!");
    clear();
    throw e;
}

void SyntacticalAnalysis::step6v()
{
    ElementL1 elementL1 = L1_.top();
    L1_.pop();
    size_t sizeOfAlt = grammar_.rPart[grammar_.infAlt[elementL1.sym].second +
            elementL1.currentAlt].size();
    for (size_t i = 0; i < sizeOfAlt; ++i) {
        L2_.pop();
    }
    ElementL2 elementL2;
    elementL2.sym =         elementL1.sym;
    elementL2.isTerminal =  false;
    L2_.push(elementL2);
}
