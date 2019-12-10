#include "contacts.h"
#include <QDebug>

Contacts::Contacts()
{
id=0;
nom="";
prenom="";
profession="";
email="";
numtel=0;
}
Contacts::Contacts(int id, QString nom,QString prenom,QString profession, QString email, int numtel)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->profession=profession;
  this->email=email;
  this->numtel=numtel;
}

int Contacts::get_id(){return id;}
QString Contacts::get_nom(){return  nom;}
QString Contacts::get_prenom(){return prenom;}
QString Contacts::get_profession(){return profession;}
QString Contacts::get_email(){return  email;}
int Contacts::get_numtel(){return numtel;}



bool Contacts::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO contacts (ID, NOM, PRENOM, PROFESSION, EMAIL, NUMTEL) "
                    "VALUES (:id, :nom, :prenom, :profession, :email, :numtel)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":profession", profession);
query.bindValue(":email", email);
query.bindValue(":numtel", numtel);
return    query.exec();
}

QSqlQueryModel * Contacts::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from contacts");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prefession"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NumTel"));
    return model;
}

bool Contacts::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from contacts where ID = :id ");
query.bindValue(":id", idd);
return    query.exec();
}

QSqlQueryModel * Contacts::trier ()
{
QSqlQuery *q=new QSqlQuery();
QSqlQueryModel *model=new     QSqlQueryModel();
q->prepare("SELECT * FROM contacts ORDER BY ID");
q->exec();
model->setQuery(*q);
return model;
}

QSqlQueryModel * Contacts::rechercher(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from contacts where ID like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

bool Contacts::modifier(Contacts c)
{
   /* QSqlQuery query;
    query.prepare("UPDATE EVENT SET  TYPE=:type,LIEU=:lieu, NUM:=num,DATEE:=datee WHERE NOM=:nom ");
       query.bindValue(":nom", e.get_nom());
       query.bindValue(":type", e.get_type());
       query.bindValue(":lieu", e.get_lieu());
       query.bindValue(":num", e.get_num());
       query.bindValue(":datee", e.get_date());
    return query.exec();*/
}





