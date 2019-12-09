#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QDebug>
#include "ajouter_employe.h"
#include <iostream>
#include <QTime>
#include <QMovie>
#include <QSound>
#include <QProgressBar>
#include <QStatusBar>
#include <QWidget>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QThread>
#include "windows.h"
#include "connection.h"
#include "mainwindow.h"
#include "setting.h"
LogIn::LogIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);

 // this->centralWidget()->setStyleSheet("background-image:url(\MyResources\"background-appromoters-advertisers-1.png\"); background-position: center; ");
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_LoginB_clicked()
{

    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QProgressBar * _progressBar = new QProgressBar();
  //  QMainWindow * mw = new QMainWindow;
  //  mw->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
  //  mw->resize(100, 100);
  //  mw->pos();
  //  mw->show();
    _progressBar->setRange(0, 100);
    _progressBar->setValue(0);
    _progressBar->setTextVisible(true);
    _progressBar->setFormat("Connecting");
    ui->statusbar->addPermanentWidget( _progressBar, 2 );
    for( int i = 0; i<=100; i+=10 ) {
       _progressBar->setValue(i);
       Sleep(50);
    }
    _progressBar->setVisible(false);

   // QMovie *movie = new QMovie(":/new/prefix1/MyResources/ajax-loader.gif");
   // movie->start();
    QSqlQuery query;
    QString select = "SELECT EMPLOYE_ID FROM COMPTE WHERE LOGIN_ID=? AND LOGIN_PASSWORD=?";
   // qDebug() << select;
    query.prepare(select);
    query.addBindValue(ui->lineEdit_UserID->text());
    query.addBindValue(ui->lineEdit_Password->text());
 query.exec();
 if (query.exec())
     {
         if (query.next())
         {
             ui->statusbar->showMessage("Connected.....",120);
             Sleep(50);
             // You login a user here
             qDebug() << query.value(0).toString()<< "is logged in";
             QString Role;
             Role =query.value(0).toString();
             QSqlQuery query_;
             QString select_ = "SELECT DEPARTEMENT FROM EMPLOYES WHERE EMPLOYES_ID=?";
           qDebug() << select_;
             query_.prepare(select_);
             query_.addBindValue(Role);
             query_.exec();

             if (query_.exec())
                 {
                     if (query_.next())
                     {
                         QString DEP;
                         DEP =query_.value(0).toString();
                         qDebug() << query_.value(0).toString();
            if (DEP == "Admin")
            {
                //this->close();
            Ajouter_Employe().exec();

            } else if (DEP=="Responsable rayon")
            {
               // this->close();
                Gestion_des_Rayons().exec();
            } else if (DEP=="Responsable RH")
            {
                this->hide();
                MainWindow_.show();
            }

         } else {
                     qDebug() << "ERROR DEP.";
                     }
             }
        else
         {
                 ui->statusbar->showMessage("Login failed. Invalid username or password.",120);
         }
     }



}
}


void LogIn::on_actionCheck_Data_Base_triggered()
{
    Connection c;
    try {
        bool test=c.createconnect();
        if(test)
{
       N.notification_DB_succ();
        }
    } catch (QString s ) {
      N.notification_DB_er();
    }
}




void LogIn::on_actionSettings_triggered()
{
s.show();
}
