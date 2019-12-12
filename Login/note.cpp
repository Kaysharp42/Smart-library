#include "note.h"
#include <QDebug>
#include <QDate>

Note::Note()
{

}

Note::Note(int id,int idn, QDateTime datee ,QString promotion, int note)
{
    this->id=id;
    this->idn=idn;
    this->datee=datee;
    this->promotion=promotion;
    this->note=note;

}

int Note:: get_id(){return id;}
int Note:: get_idn(){return idn;}
int Note::get_note(){return note;}
QString Note::get_promotion(){return promotion;}
QDateTime Note::get_datee(){return datee;}


bool Note::ajouter2()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res2= QString::number(idn);
    QString res1= QString::number(note);


    query.prepare("INSERT INTO NOTE (ID,IDN, DATE1, PROMOTION, NOTE) "
                        "VALUES (:id,:idn, :d, :promotion, :note)");

   query.bindValue(":id", res);
   query.bindValue(":idn", res2);
   query.bindValue(":d", datee);
   query.bindValue(":promotion", promotion);
   query.bindValue(":note", res1);

   return    query.exec();
}

QSqlQueryModel * Note::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from note");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Promotion"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Note"));
     return model;

}

bool Note::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from note where ID = :id ");
query.bindValue(":id", idd);
return    query.exec();
}
