#include "Headers/mainwindow.h"

#include <QApplication>
#include <QFile>

// main файл для запуска самого приложения и главного окна приложения.
// Вызывается конструктор главного окна приложения
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
