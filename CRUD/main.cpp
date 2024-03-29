#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    connexion c;

    try {
            bool test=c.ouvrirConnexion();
            if(test)
    {
            w.show();
          QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
            }
        } catch (QString s ) {
           qDebug()<<s;
          QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                 QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
    return a.exec();

}
