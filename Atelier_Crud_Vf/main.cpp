#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "cnx.h"
#include <QtDebug>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    cnx s;
    s.show();
    return a.exec();
}
