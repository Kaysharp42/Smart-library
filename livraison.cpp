#include "livraison.h"
#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include<QString>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlQueryModel>
#include <QSqlError>
livraison::livraison()
{
    num_liv="";
    date_liv="" ;
    adresse="" ;
}
livraison::livraison(QString num_liv,QString adresse,QString date_liv)
{

   this->num_liv=num_liv;
    this->adresse=adresse;
    this->date_liv=date_liv;
}
bool livraison::ajouterlivraison()
{
 QSqlQuery q;
 q.prepare("INSERT into livraison (num_liv, date_liv,adresse,) VALUES (:num_liv, :date_liv, :adresse,)");
 q.bindValue(":num_liv",num_liv);
 q.bindValue(":date_liv",date_liv);
 q.bindValue("type",adresse);

 if (q.exec()){
     qDebug()<<"livraison ajouté";
     return true;
 }
 else{
     qDebug()<<q.lastError().text();

     return false;
 }

}
QSqlQueryModel *livraison::getAlllivraison()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM livraison");
    return model;
}
void livraison::deletelivraison(QString num_liv)
    {
        QSqlQuery q;
        q.prepare("DELETE from livraison where num_liv=:num_liv");
        q.bindValue(":num_liv",num_liv);
        q.exec();
    }
void livraison::modifierlivraison(QString num_liv)
{
    QSqlQuery q;
    q.prepare("UPDATE livraison set  num_liv=:num_liv   date_liv= :date_liv and  adresse = :adresse ");
    q.bindValue(":num_liv",this->num_liv);
    q.bindValue(":date_liv",this->date_liv);
    q.bindValue(":adresse", this->adresse);
    q.exec();
}
QSqlQueryModel* livraison::afficherlivraison()
{

    QSqlQueryModel*model = new QSqlQueryModel() ;
    model->setQuery("SELECT *FROM livraison");
    model->setHeaderData(0,Qt::Horizontal ,QObject::tr("livraison"));
    return model ;

}
livraison livraison::getlivraison(QString num_liv)
{
    livraison *p = new livraison();
   QSqlQuery q;
    q.prepare("SELECT * from livraison where num_liv=:num_liv");
    q.bindValue(":num_liv",num_liv);
    q.exec();
    while (q.next()) {
            p->setnum_liv(q.value(1).toString());
            p->setdate_liv(q.value(2).toString()); //q.value(index colonne base de donné)
            p->setadresse(q.value(3).toString());

           }
return *p;
}
