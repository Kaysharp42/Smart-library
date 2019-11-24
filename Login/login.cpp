#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QDebug>
#include "ajouter_employe.h"
#include <iostream>
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
             // You login a user here

             qDebug() << query.value(0).toString()<< "is logged in";
             QString Role;
             Role =query.value(0).toString();
             QSqlQuery query_;
             QString select_ = "SELECT DEPARTEMENT FROM EMPLOYES WHERE EMPLOYE_ID=?";
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

            } else if (DEP=="Responsable stock")
            {
               // this->close();
                Gestion_des_Rayons().exec();
            }

         } else {
                     qDebug() << "ERROR DEP.";
                     }
             }
        else
         {
             qDebug() << "Login failed. Invalid username or password.";
         }
     }



}
}

