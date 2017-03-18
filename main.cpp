#include <QCoreApplication>
// TODO: ChernyshovSV - Убрать после завершения отладки.
#include <QDebug>

#include "lexicalanaliz.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Формирование таблиц и массивов.
    // Массив служебных слов.
    QVector<QString> serviceWords;
    serviceWords.push_back("void");
    serviceWords.push_back("main");
    serviceWords.push_back("int");
    serviceWords.push_back("if");
    serviceWords.push_back("else");
    serviceWords.push_back("while");

    // Массив верных знаков.
    QVector<QString> rightSigns;
    rightSigns.push_back("+");
    rightSigns.push_back(",");
    rightSigns.push_back(";");
    rightSigns.push_back("-");
    rightSigns.push_back("*");
    rightSigns.push_back("{");
    rightSigns.push_back("}");
    rightSigns.push_back("(");
    rightSigns.push_back(")");
    rightSigns.push_back("=");
    rightSigns.push_back(">");
    rightSigns.push_back("<");
    rightSigns.push_back("==");
    rightSigns.push_back(">=");
    rightSigns.push_back("<=");
    rightSigns.push_back("/");
    rightSigns.push_back("!");
    rightSigns.push_back("&&");
    rightSigns.push_back("||");
    rightSigns.push_back("!=");
    rightSigns.push_back("&");
    rightSigns.push_back("|");

    QString fileName = "main.txt";
    LexicalAnaliz lexicalAnaliz(fileName);
    if (lexicalAnaliz.isSetProgram()) {
        qDebug() << "The file is opened!";
    } else {
        qDebug() << "The file is not opened!";
    }
    lexicalAnaliz.setRightSigns(rightSigns);
    lexicalAnaliz.setServiceWords(serviceWords);

    if (!lexicalAnaliz.run()) {
        qDebug() << "Lexical analiz stoped!";
        return 0;
    }

    lexicalAnaliz.showConstsTable();
    lexicalAnaliz.showIdentifiers();
    lexicalAnaliz.showConvolution();

    return a.exec();
}
