#include "reclamations.h"
#include <QDebug>

Reclamations::Reclamations()
{
num=0;
titre="";
redacteur="";
}

Reclamations::Reclamations(int num, QString titre,QString redacteur)
{
  this->num=num;
  this->titre=titre;
  this->redacteur=redacteur;
}

int Reclamations::get_num(){return num;}
QString Reclamations::get_titre(){return  titre;}
QString Reclamations::get_redacteur(){return redacteur;};


bool Reclamations::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO reclamations (NUM, TITRE, REDACTEUR) "
                    "VALUES (:num, :titre, :redacteur)");
query.bindValue(":num", num);
query.bindValue(":titre", titre);
query.bindValue(":redacteur", redacteur);

return    query.exec();
}

QSqlQueryModel * Reclamations::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamations");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Redacteur"));
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

