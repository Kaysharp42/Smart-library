#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    connexion c;
    try {
        bool test=c.createconnexion();
        if (test)
            w.show();
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                QObject::tr("connection successful.\n"
                            "click cancel to exit."),QMessageBox::Cancel);

    } catch (QString s) {
        qDebug()<<s;
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                QObject::tr("connection successful.\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    return a.exec();}

