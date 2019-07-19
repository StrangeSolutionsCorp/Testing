#include "mainwindow.h"
#include "fstream"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <winsock2.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;


    w.show();



    return a.exec();
}
