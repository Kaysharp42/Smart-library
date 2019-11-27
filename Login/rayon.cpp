#include "rayon.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
Rayon::Rayon()
{
    m_Id=0;
    m_nbr_etag=0;
}
Rayon::Rayon(int id,int nbr,QString c)
{
    m_Id=id;
    m_nbr_etag=nbr;
    m_Categorie=c;

}
bool Rayon::Ajouter_Rayon()
{
    //if id not int  do
    //QString res= QString::number(id);
    // query.bindValue(":id", res);
    QSqlQuery query;
          query.prepare("INSERT INTO RAYON (ID, NBR_ETAGERE,CATEGORY)"
                        "VALUES (:id,:nbr,:cat)");
          query.bindValue(":id", m_Id);
          query.bindValue(":nbr", m_nbr_etag);
          query.bindValue(":cat",m_Categorie);
          return query.exec();
}
QSqlQueryModel * Rayon::Afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM RAYON");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBR_ETAGERE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORY"));
            return model;
}

bool Rayon::modifier(int id, int nbr,QString cat)
{
    QSqlQuery query;
          query.prepare("UPDATE RAYON  SET NBR_ETAGERE =:nbr , CATEGORY=:cat WHERE ID=:id  " );
          query.bindValue(":nbr", nbr);
           query.bindValue(":id", id);
           query.bindValue(":cat", cat);
          return query.exec();
}
bool Rayon::Supprimer(int id)
{
    QSqlQuery query;
          query.prepare("DELETE FROM RAYON WHERE ID =:id");
          query.bindValue(":id",id);
          return query.exec();
}

