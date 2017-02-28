
#include <QCoreApplication>
// TODO: ChernyshovSV - Убрать после завершения отладки.
#include <QDebug>

// TODO: ChernyshovSV - Потом убрать подключение, будет в другом месте.
#include "scaner.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Scaner scaner("main.txt");
    if (scaner.isFile()) {
        qDebug() << "The file is opened!";
    } else {
        qDebug() << "The file is not opened!";
    }


    return a.exec();
}
