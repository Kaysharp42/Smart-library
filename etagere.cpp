#include "etagere.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>

Etagere::Etagere()
{
    m_etagere_id="";
    m_ID=0;
}
Etagere::Etagere(QString e_id,int r_id)
{
m_etagere_id=e_id;
m_ID=r_id;
}
bool Etagere::Ajouter_Etagere()
{
    //if id not int  do
    //QString res= QString::number(id);
    // query.bindValue(":id", res);
    qDebug() << m_ID ;
    QSqlQuery query;
          query.prepare("INSERT INTO ETAGERE (ETAGERE_ID,ID)"
                        "VALUES (:e_id,:r_id)");
          query.bindValue(":e_id",m_etagere_id );
          query.bindValue(":r_id",m_ID );
          return query.exec();
}
QSqlQueryModel * Etagere::Afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM ETAGERE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ETAGERE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTT_PRODUIT"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
            return model;
}


bool Etagere::Supprimer(QString id)
{
    QSqlQuery query;
          query.prepare("DELETE FROM ETAGERE WHERE ETAGERE_ID =:id");
          query.bindValue(":id",id);
          return query.exec();
}
