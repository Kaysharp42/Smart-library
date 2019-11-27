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
Etagere::Etagere(QString e_id, QString p_id, int r_id, int qtt, int num)
{
m_etagere_id=e_id;
m_produit_id=p_id;
m_ID=r_id;
QTT_produit=qtt;
m_num_etage=num;
}
Etagere::Etagere(QString e_id,int id)
{
    m_etagere_id=e_id;
    m_ID=id;
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
bool Etagere::Ajouter_Produit()
{
    qDebug() << m_produit_id ;
    qDebug() << QTT_produit ;
    qDebug() << m_num_etage ;
    qDebug() << m_etagere_id ;

    QSqlQuery query;
          query.prepare("UPDATE ETAGERE  SET PRODUIT_ID =:p_id, QTT_PRODUIT=:qtt, NUM_ETAGE=:num WHERE ETAGERE_ID=:e_id" );
          query.bindValue(":p_id", m_produit_id);
           query.bindValue(":qtt", QTT_produit);
           query.bindValue(":num", m_num_etage);
           query.bindValue(":e_id", m_etagere_id);
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
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_ETAGE"));
            return model;
}


bool Etagere::Supprimer(QString id)
{
    QSqlQuery query;
          query.prepare("DELETE FROM ETAGERE WHERE ETAGERE_ID =:id");
          query.bindValue(":id",id);
          return query.exec();
}
bool Etagere::modifier_Qtt(int qtt,QString p_id)
{
    QSqlQuery query;
          query.prepare("UPDATE ETAGERE  SET QTT_PRODUIT=:qtt WHERE PRODUIT_ID =:p_id" );
          query.bindValue(":qtt", qtt);
           query.bindValue(":p_id", p_id);
          return query.exec();
}
bool Etagere::modifier_etage(int etage,QString p_id)
{
    QSqlQuery query;
          query.prepare("UPDATE ETAGERE  SET NUM_ETAGE=:num WHERE PRODUIT_ID =:p_id" );
          query.bindValue(":num", etage);
           query.bindValue(":p_id", p_id);
          return query.exec();
}
