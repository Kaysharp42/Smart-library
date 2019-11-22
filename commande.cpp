#include "commande.h"
#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include<QString>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QtSql/QSqlQueryModel>
#include <QSqlError>
paiement::paiement()
{

    num_cmd="";
    date_paiement="" ;
    type="" ;
    montant=0 ;
}
paiement::paiement(QString num_cmd,QString type,QString date_paiement,int montant)
{

   this->num_cmd=num_cmd;
    this->type=type;
    this->date_paiement=date_paiement;
    this->montant=montant;
}
bool paiement::ajouterpaiement()
{
 QSqlQuery q;
 q.prepare("INSERT into paiements (num_cmd, date_paiement, type, montant,) VALUES (:num_cmd, :date_paiement, :type, :montant,)");
 q.bindValue(":num_cmd",num_cmd);
 q.bindValue(":date_paiement",date_paiement);
 q.bindValue("type",type);
 q.bindValue(":montant",montant);

 if (q.exec()){
     qDebug()<<"paiement  ajouté";
     return true;
 }
 else{
     qDebug()<<q.lastError().text();

     return false;
 }

}
QSqlQueryModel *paiement::getAllpaiement()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenements");
    return model;
}


void paiement::deletepaiement(QString num_cmd)
    {
        QSqlQuery q;
        q.prepare("DELETE from evenement where nom_evenement=:nom_evenement");
        q.bindValue(":nom_evenement",num_cmd);
        q.exec();
    }
void paiement::modifierpaiement(QString num_cmd)
{
    QSqlQuery q;
    q.prepare("UPDATE evenements set  num_cmd=:num_cmd   date_paiement= :date_paiement and  type = :type montant = :montant ");
    q.bindValue(":num_cmd",this->num_cmd);
    q.bindValue(":date_paiement",this->date_paiement);
    q.bindValue(":type", this->type);
    q.bindValue(":montant",this->montant) ;

    q.exec();
}




QSqlQueryModel* paiement::afficherpaiement()
{

    QSqlQueryModel*model = new QSqlQueryModel() ;
    model->setQuery("SELECT *FROM paiements");
    model->setHeaderData(0,Qt::Horizontal ,QObject::tr("paiements"));
    return model ;

}
paiement paiement::getpaiement(QString num_cmd)
{
    paiement *p = new paiement();
   QSqlQuery q;
    q.prepare("SELECT * from paiements where num_cmd=:num_cmd");
    q.bindValue(":nom_evenement",num_cmd);
    q.exec();
    while (q.next()) {
            p->setnum_cmd(num_cmd);
            p->setdate_paiement(q.value(1).toString()); //q.value(index colonne base de donné)
            p->settype(q.value(3).toString());
            p->setmontant(q.value(4).toInt());
           }
return *p;
}
