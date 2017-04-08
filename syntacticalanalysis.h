#pragma once

#include <stack>

#include "global.h"

class SyntacticalAnalysis
{
public:
    SyntacticalAnalysis();

private:
    std::stack<ElementL1> L1_;
    std::stack<ElementL2> L2_;

    // Текущий терминал входной цепочки.
    unsigned int current_;

    // Состояние работы.
    ParserState state_;

    // Входная цепочка.
    QVector<Descriptor> convolution_;

    // Таблицы.
    QVector<QString> serviceWords_;
    QVector<QString> rightSigns_;
    QVector<QString> identifiers_;
    QVector<QString> constsTable_;

    // Грамматика.
    Grammar grammar_;

    // Вывод.
    std::stack<int> conclusion_;
};
