#pragma once

#include <stack>

#include "global.h"

class SyntacticalAnalysis
{
public:
    SyntacticalAnalysis();

    /**
     * @brief clear очищает полученные данные для дальнейшего использования
     * объекта.
     */
    void clear();

    // Геттеры.
    std::stack<ElementL1> stackL1() const;
    std::stack<ElementL2> stackL2() const;
    QVector<Descriptor> convolution() const;
    QVector<QString> serviceWords() const;
    QVector<QString> rightSigns() const;
    QVector<QString> identifiers() const;
    QVector<QString> constsTable() const;
    Grammar grammar() const;
    std::stack<int> conclusion() const;

    // Сеттеры.
    void setConvolution(const QVector<Descriptor> & convolution);
    void setServiceWords(const QVector<QString> & serviceWords);
    void setRightSigns(const QVector<QString> & rightSigns);
    void setIdentifiers(const QVector<QString> & identifiers);
    void setConstsTable(const QVector<QString> & constsTable);
    void setGrammar(const Grammar & grammar);

    /**
     * @brief run выполняет синтаксический анализ.
     */
    void run();

private:
    void step1();
    void step2();
    void step3();
    void step3Else();
    void step4();
    void step5();
    void step6();
    void step6a();
    void step6b();
    void step6v();

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
