#include "etudiant.h"
#include <QDebug>
Clients::Clients()
{
id=0;
nom="";
prenom="";
adresse="";
}
Clients::Clients(int id,QString nom,QString prenom,QString adresse)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
}
QString Clients::get_nom(){return  nom;}
QString Clients::get_prenom(){return prenom;}
QString Clients::get_adresse(){return adresse;}
int Clients::get_id(){return  id;}

bool Clients::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO clients (id, NOM, PRENOM, ADRESSE) "
                    "VALUES (:id, :nom, :prenom, :adresse)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);

return    query.exec();
}

QSqlQueryModel * Clients::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from clients");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
}

bool Clients::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from clients where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

