#include "etudiant.h"
#include <QDebug>
#include <QDate>
#include <QString>
#include <QMessageBox>
#include<iostream>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QTableView>

Etudiant::Etudiant()
{}

Etudiant::Etudiant(int id,QString nom,QString prenom, QDateTime datee,QString fonction,QString sexe,int tel)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->datee=datee;
  this->fonction=fonction;
  this->sexe=sexe;
  this->tel=tel;
}
QString Etudiant::get_nom(){return  nom;}
QString Etudiant::get_prenom(){return prenom;}
QDateTime Etudiant::get_datee(){return  datee ;}
QString Etudiant::get_fonction(){return fonction;}
QString Etudiant::get_sexe(){return sexe;}
int Etudiant::get_id(){return  id;}
int Etudiant::get_tel(){return  tel;}

bool Etudiant::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(tel);

query.prepare("INSERT INTO ETUDIANT (ID, NOM, PRENOM, NAISSANCE, FONCTION, SEXE,TELEPHONE) "
                    "VALUES (:id, :nom, :prenom, :d, :fonction, :sexe, :tel )");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":d", datee);
query.bindValue(":fonction", fonction);
query.bindValue(":sexe", sexe);
query.bindValue(":tel", res1);

return    query.exec();
}

QSqlQueryModel * Etudiant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" Fonction"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Télephone"));
    return model;
}



bool Etudiant::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


QSqlQueryModel * Etudiant::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiant order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" Fonction"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Télephone"));
    return model;
}

QSqlQueryModel * Etudiant::rechercher(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from ETUDIANT where NOM like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

