#pragma once

#include "scaner.h"

class LexicalAnaliz
{
public:
    // Геттеры.
    QVector<QString> serviceWords();
    QVector<QString> rightSigns();
    QVector<Descriptor> convolution();
    QVector<QString> identifiers();
    QVector<QString> constsTable();

    // Сеттеры.
    void setServiceWords(const QVector<QString> & serviceWords);
    void setRightSigns(const QVector<QString> & rightSigns);

    // Проверка полей класса.
    bool serviceWordsIsEmpty();
    bool rightSignsIsEmpty();
    bool convolutionIsEmpty();
    bool identifiersIsEmpty();
    bool constsTableIsEmpty();

    /**
     * @brief clear - обнуляет лексический анализатор, очищая все его внутренние поля.
     */
    void clear();

    LexicalAnaliz(const QString & nameFile);
    LexicalAnaliz(const QByteArray & byteArray);
    bool setNameFile(const QString & nameFile);
    void setByteArray(const QByteArray & byteArray);
    void setContent(const QString & string);
    bool isSetProgram();
    QByteArray program();

    /**
     * @brief run - выполняется лексический анализ.
     * @return - возвращает true, если анализ выполнен успешно, или false в противном
     * случае. Все ошибки выводятся в консоль.
     */
    bool run();

    void showConvolution();
    void showIdentifiers();
    void showConstsTable();

private:
    QVector<QString> serviceWords_;
    QVector<QString> rightSigns_;

    /**
     * @brief convolution_ - Лексическая светртка получаемая в результате лексического
     * анализа.
     */
    QVector<Descriptor> convolution_;
    QVector<QString> identifiers_;
    QVector<QString> constsTable_;
    Scaner scaner_;
};
