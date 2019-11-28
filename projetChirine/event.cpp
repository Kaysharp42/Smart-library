#include "event.h"
#include <QDebug>

Event::Event()
{
num=0;
nom="";
type="";
datee=0;
lieu="";
}
Event::Event(int num, QString nom,QString type,int datee,QString lieu)
{
  this->num=num;
  this->nom=nom;
  this->type=type;
  this->lieu=lieu;
  this->datee=datee;
}
int Event::get_num(){return num;}
QString Event::get_nom(){return  nom;}
QString Event::get_type(){return type;}
int Event::get_date(){return datee;}
QString Event::get_lieu(){return lieu;}

bool Event::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO event (NOM, TYPE, LIEU, NUM, DATEE) "
                    "VALUES (:nom, :type, :lieu, :num, :datee)");
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":lieu", lieu);
query.bindValue(":num", num);
query.bindValue(":datee", datee);

return    query.exec();
}



QSqlQueryModel * Event::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from event");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
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

QSqlQueryModel * Event::trier ()
{
QSqlQuery *q=new QSqlQuery();
QSqlQueryModel *model=new     QSqlQueryModel();
q->prepare("SELECT * FROM EVENT ORDER BY NUM");
q->exec();
model->setQuery(*q);
return model;
}

QSqlQueryModel * Event::rechercher(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from EVENT where NOM like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}






