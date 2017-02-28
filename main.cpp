
#include <QCoreApplication>
// TODO: ChernyshovSV - Убрать после завершения отладки.
#include <QDebug>

// TODO: ChernyshovSV - Потом убрать подключение, будет в другом месте.
#include "scaner.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Формирование таблиц и списков.
    // Массив служебных слов.
    QVector<QString> serviceWords;
    serviceWords.push_back("void");
    serviceWords.push_back("main");
    serviceWords.push_back("int");
    serviceWords.push_back("if");
    serviceWords.push_back("else");
    serviceWords.push_back("while");

    // Массив верных знаков.
    QVector<char> rightSigns;
    rightSigns.push_back('+');
    rightSigns.push_back(',');
    rightSigns.push_back(';');
    rightSigns.push_back('-');
    rightSigns.push_back('*');
    rightSigns.push_back('{');
    rightSigns.push_back('}');
    rightSigns.push_back('(');
    rightSigns.push_back(')');

    Scaner scaner("main.txt");
    if (scaner.isFile()) {
        qDebug() << "The file is opened!";
    } else {
        qDebug() << "The file is not opened!";
    }
    scaner.setRightSigns(rightSigns);
    scaner.setServiceWords(serviceWords);


    return a.exec();
}
