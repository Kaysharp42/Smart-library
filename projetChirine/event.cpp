#include "event.h"
#include <QDebug>

Event::Event()
{
num=0;
nom="";
type="";
lieu="";
}
Event::Event(int num, QString nom,QString type,QString lieu)
{
  this->num=num;
  this->nom=nom;
  this->type=type;
  this->lieu=lieu;
}
int Event::get_num(){return num;}
QString Event::get_nom(){return  nom;}
QString Event::get_type(){return type;}
QString Event::get_lieu(){return lieu;}

bool Event::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO event (NUM, NOM, TYPE, LIEU) "
                    "VALUES (:num, :nom, :type, :lieu)");
query.bindValue(":num", num);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":lieu", lieu);

return    query.exec();
}



QSqlQueryModel * Event::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from event");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num"));
    return model;
}

bool Event::supprimer(int numm)
{
QSqlQuery query;
QString res= QString::number(numm);
query.prepare("Delete from event where NUM = :num ");
query.bindValue(":num", numm);
return    query.exec();
}





