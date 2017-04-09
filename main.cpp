#include <QCoreApplication>

#include "lexicalanaliz.h"
#include "syntacticalanalysis.h"

Grammar makeGrammar()
{
    Grammar grammar;
    grammar.lPart.push_back("S");
    grammar.rPart.push_back(QVector<QString>{"void", "main", "(", ")", "A"});

    grammar.lPart.push_back("A");
    grammar.rPart.push_back(QVector<QString>{"{", "B", "}"});

    grammar.lPart.push_back("B");
    grammar.rPart.push_back(QVector<QString>{"D"});

    grammar.lPart.push_back("B");
    grammar.rPart.push_back(QVector<QString>{"D", "B"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"if", "A"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"if", "A", "else", "A"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"if", "D"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"if", "A", "else", "D"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"if", "D", "else", "A"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"if", "D", "else", "D"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"while", "(", "U", ")", "A"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"while", "(", "U", ")", "D"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"K"});

    grammar.lPart.push_back("D");
    grammar.rPart.push_back(QVector<QString>{"I", "=", "K"});

    grammar.lPart.push_back("K");
    grammar.rPart.push_back(QVector<QString>{"-", "K"});

    grammar.lPart.push_back("K");
    grammar.rPart.push_back(QVector<QString>{"+", "K"});

    grammar.lPart.push_back("K");
    grammar.rPart.push_back(QVector<QString>{"(", "K", ")"});

    grammar.lPart.push_back("K");
    grammar.rPart.push_back(QVector<QString>{"T", "O", "K"});

    grammar.lPart.push_back("K");
    grammar.rPart.push_back(QVector<QString>{"T"});

    grammar.lPart.push_back("K");
    grammar.rPart.push_back(QVector<QString>{"(", "K", ")", "O", "K"});

    grammar.lPart.push_back("T");
    grammar.rPart.push_back(QVector<QString>{"I"});

    grammar.lPart.push_back("T");
    grammar.rPart.push_back(QVector<QString>{"C"});

    grammar.lPart.push_back("U");
    grammar.rPart.push_back(QVector<QString>{"(", "U", ")"});

    grammar.lPart.push_back("U");
    grammar.rPart.push_back(QVector<QString>{"!", "U"});

    grammar.lPart.push_back("U");
    grammar.rPart.push_back(QVector<QString>{"Y"});

    grammar.lPart.push_back("U");
    grammar.rPart.push_back(QVector<QString>{"Y", "E", "U"});

    grammar.lPart.push_back("U");
    grammar.rPart.push_back(QVector<QString>{"(", "U", ")", "L", "U"});

    grammar.lPart.push_back("Y");
    grammar.rPart.push_back(QVector<QString>{"K"});

    grammar.lPart.push_back("O");
    grammar.rPart.push_back(QVector<QString>{"+"});

    grammar.lPart.push_back("O");
    grammar.rPart.push_back(QVector<QString>{"-"});

    grammar.lPart.push_back("O");
    grammar.rPart.push_back(QVector<QString>{"*"});

    grammar.lPart.push_back("O");
    grammar.rPart.push_back(QVector<QString>{"/"});

    grammar.lPart.push_back("O");
    grammar.rPart.push_back(QVector<QString>{"&"});

    grammar.lPart.push_back("O");
    grammar.rPart.push_back(QVector<QString>{"|"});

    grammar.lPart.push_back("E");
    grammar.rPart.push_back(QVector<QString>{">"});

    grammar.lPart.push_back("E");
    grammar.rPart.push_back(QVector<QString>{"<"});

    grammar.lPart.push_back("E");
    grammar.rPart.push_back(QVector<QString>{"=="});

    grammar.lPart.push_back("E");
    grammar.rPart.push_back(QVector<QString>{">="});

    grammar.lPart.push_back("E");
    grammar.rPart.push_back(QVector<QString>{"<="});

    grammar.lPart.push_back("E");
    grammar.rPart.push_back(QVector<QString>{"!="});

    grammar.lPart.push_back("L");
    grammar.rPart.push_back(QVector<QString>{"||"});

    grammar.lPart.push_back("L");
    grammar.rPart.push_back(QVector<QString>{"&&"});

    QPair<int, int> pair;
    pair.first =    1;
    pair.second =   0;
    grammar.infAlt.insert("S", pair);

    pair.first =    1;
    pair.second =   1;
    grammar.infAlt.insert("A", pair);

    pair.first =    2;
    pair.second =   2;
    grammar.infAlt.insert("B", pair);

    pair.first =    10;
    pair.second =   4;
    grammar.infAlt.insert("D", pair);

    pair.first =    6;
    pair.second =   14;
    grammar.infAlt.insert("K", pair);


    pair.first =    2;
    pair.second =   20;
    grammar.infAlt.insert("T", pair);

    pair.first =    5;
    pair.second =   22;
    grammar.infAlt.insert("U", pair);

    pair.first =    1;
    pair.second =   27;
    grammar.infAlt.insert("Y", pair);

    pair.first =    6;
    pair.second =   28;
    grammar.infAlt.insert("O", pair);

    pair.first =    6;
    pair.second =   34;
    grammar.infAlt.insert("E", pair);

    pair.first =    2;
    pair.second =   40;
    grammar.infAlt.insert("L", pair);

    return grammar;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {
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

        SyntacticalAnalysis syntacticalAnalysis;
        syntacticalAnalysis.setConstsTable(lexicalAnaliz.constsTable());
        syntacticalAnalysis.setConvolution(lexicalAnaliz.convolution());
        syntacticalAnalysis.setIdentifiers(lexicalAnaliz.identifiers());
        syntacticalAnalysis.setRightSigns(rightSigns);
        syntacticalAnalysis.setServiceWords(serviceWords);

        Grammar grammar = makeGrammar();
        syntacticalAnalysis.setGrammar(grammar);
        std::stack<int> stack = syntacticalAnalysis.conclusion();

        qDebug() << "Левый вывод: ";
        while(!stack.empty()) {
            qDebug() << stack.top();
            stack.pop();
        }

    }
    catch (ErrorParser e) {
        qDebug() << e.getError();
    }

    return a.exec();
}
