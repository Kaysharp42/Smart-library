#include "reclamation.h"
#include <QDebug>

Reclamation::Reclamation()
{
num=0;
titre="";
redacteur="";
}

Reclamation::Reclamation(int num, QString titre,QString redacteur)
{
  this->num=num;
  this->titre=titre;
  this->redacteur=redacteur;
}

int Reclamation::get_num(){return num;}
QString Reclamation::get_titre(){return  titre;}
QString Reclamation::get_redacteur(){return redacteur;};


bool Reclamation::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO reclamations (NUM, TITRE, REDACTEUR) "
                    "VALUES (:num, :titre, :redacteur)");
query.bindValue(":num", num);
query.bindValue(":titre", titre);
query.bindValue(":redacteur", redacteur);

return    query.exec();
}

QSqlQueryModel * Reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamations");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Redacteur"));
    return model;
}

bool Reclamation::supprimer(int numm)
{
QSqlQuery query;
QString res= QString::number(numm);
query.prepare("Delete from reclamations where NUM = :num ");
query.bindValue(":num", numm);
return    query.exec();
}

