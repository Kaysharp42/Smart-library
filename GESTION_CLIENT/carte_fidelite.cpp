#include "carte_fidelite.h"
#include <QDebug>

carte_fidelite::carte_fidelite()
{
    id=0;
    date_debut="";
    date_expiration="";
    nombre_points=0;
}
carte_fidelite::carte_fidelite(int id,int nombre_points,QString date_debut,QString date_expiration)
{
    this->id=id;
    this->nombre_points=nombre_points;
    this->date_debut=date_debut;
    this->date_expiration=date_expiration;
}


QString carte_fidelite::get_date_debut(){return date_debut;}
QString carte_fidelite::get_date_expiration(){return date_expiration;}
int carte_fidelite::get_id(){return  id;}
int carte_fidelite::get_nombre_points(){return  nombre_points;}

bool carte_fidelite::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO carte_fidelite (id,nombre_points, DATE_DEBUT, DATE_EXPIRATION) "
                    "VALUES (:id,:nombre_points, :date_debut, :date_expi)");
query.bindValue(":id", res);
query.bindValue(":nombre_points", nombre_points);
query.bindValue(":date_debut", date_debut);
query.bindValue(":date_expi", date_expiration);

return    query.exec();
}

bool carte_fidelite::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("UPDATE carte_fidelite SET nombre_points=:nombre_points,DATE_DEBUT=:date_debut,DATE_EXPIRATION=:date_expi WHERE ID=:id");
query.bindValue(":id", res);
query.bindValue(":nombre_points", nombre_points);
query.bindValue(":date_debut", date_debut);
query.bindValue(":date_expi", date_expiration);

return    query.exec();
}

QSqlQueryModel * carte_fidelite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from carte_fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre de points"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de debut"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date d'expiration"));
    return model;
}



bool carte_fidelite::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from carte_fidelite where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

