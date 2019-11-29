#include "note.h"
#include <QDebug>
#include <QDate>

Note::Note()
{

}

Note::Note(int id, QDateTime datee ,QString promotion, int note)
{
    this->id=id;
    this->datee=datee;
    this->promotion=promotion;
    this->note=note;

}

int Note:: get_id(){return id;}
int Note::get_note(){return note;}
QString Note::get_promotion(){return promotion;}
QDateTime Note::get_datee(){return datee;}


bool Note::ajouter2()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(note);


    query.prepare("INSERT INTO NOTE (ID, DATE1, PROMOTION, NOTE) "
                        "VALUES (:id, :d, :promotion, :note)");

   query.bindValue(":id", res);
   query.bindValue(":d", datee);
   query.bindValue(":promotion", promotion);
   query.bindValue(":note", res1);

   return    query.exec();
}

QSqlQueryModel * Note::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from note");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
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
