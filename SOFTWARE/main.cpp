#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SERIAL PORT COMMUNICATION GUI");
    w.setWindowIcon(QIcon("D:\\MY_WORK\\tai_lieu\\logo\\Logo BK.png"));
    w.show();

    return a.exec();
}
