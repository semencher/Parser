
#include <QCoreApplication>
// TODO: ChernyshovSV - Убрать после завершения отладки.
#include <QDebug>

// TODO: ChernyshovSV - Потом убрать подключение, будет в другом месте.
#include "scaner.h"

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
    Scaner scaner(fileName);
    if (scaner.isSetProgram()) {
        qDebug() << "The file is opened!";
    } else {
        qDebug() << "The file is not opened!";
    }
    scaner.setRightSigns(rightSigns);
    scaner.setServiceWords(serviceWords);

    Lexem lexem;
    lexem = scaner.next();
    while (lexem.word != "") {
        qDebug() << lexem.word;
        if (lexem.type == Identifier) {
            qDebug() << "Identifier";
        }
        if (lexem.type == IntegerConst) {
            qDebug() << "IntegerConst";
        }
        if (lexem.type == RightSignL) {
            qDebug() << "RightSignL";
        }
        if (lexem.type == ServiceWord) {
            qDebug() << "ServiceWord";
        }
        if (lexem.type == ErrorLexem) {
            qDebug() << "ErrorLexem";
        }
        qDebug() << "\n";
        lexem = scaner.next();
    }

    return a.exec();
}
