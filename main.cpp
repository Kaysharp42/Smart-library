#include "login.h"

#include <QApplication>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogIn w;
    w.show();  
    Connection c;
    try {
        bool test=c.createconnect();
        if(test)
{
        w.show();
       // QMessageBox::critical(nullptr, QObject::tr("database is open"),
          //        QObject::tr("connection successful.\n"
               //             "Click Cancel to exit."), QMessageBox::Cancel);
        }
    } catch (QString s ) {
      //  qDebug()<<s;
      // QMessageBox::critical(nullptr, QObject::tr("database is not open"),
          //        QObject::tr("connection failed.\n"
           //                     "Click Cancel to exit."), QMessageBox::Cancel);
    }





    return a.exec();
}
