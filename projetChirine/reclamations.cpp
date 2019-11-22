#include "reclamations.h"
#include <QDebug>

Reclamations::Reclamations()
{
num=0;
titre="";
redacteur="";
destinataire="";
type.addItem("Foire");
type.addItem("Conference");
type.addItem("Signature livre");
}

Reclamations::Reclamations(int num, QString titre,QString redacteur, QString destinataire)
{
  this->num=num;
  this->titre=titre;
  this->redacteur=redacteur;
  this->destinataire=destinataire;
}

int Reclamations::get_num(){return num;}
QString Reclamations::get_titre(){return  titre;}
QString Reclamations::get_redacteur(){return redacteur;}
QString Reclamations::get_destinataire(){return destinataire;}



bool Reclamations::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO reclamations (NUM, TITRE, REDACTEUR, DESTINATAIRE) "
                    "VALUES (:num, :titre, :redacteur, :destinataire)");
query.bindValue(":num", num);
query.bindValue(":titre", titre);
query.bindValue(":redacteur", redacteur);
query.bindValue(":destinataire", destinataire);

return    query.exec();
}

QSqlQueryModel * Reclamations::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamations");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Redacteur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Destinataire"));
    return model;
}

bool Reclamations::supprimer(int numm)
{
QSqlQuery query;
QString res= QString::number(numm);
query.prepare("Delete from reclamations where NUM = :num ");
query.bindValue(":num", numm);
return    query.exec();
}

