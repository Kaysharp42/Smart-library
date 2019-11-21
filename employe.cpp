#include "employe.h"
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>

Employe::Employe()
{
m_Id="";
}
Employe::Employe(QString Id,QString loginid ,QString password)
{
    this->m_Id=Id;
    this->m_login_id=loginid;
    this->m_login_Password=password;


    }

bool Employe::Ajouter_Employe()
{
    //if id not int  do
    //QString res= QString::number(id);
    // query.bindValue(":id", res);
    QSqlQuery query;
          query.prepare("INSERT INTO COMPTE (EMPLOYE_ID,LOGIN_ID,LOGIN_PASSWORD)"
                        "VALUES (:empid,:loginid,:loginpass)");
          query.bindValue(":empid", m_Id);
          query.bindValue(":loginid", m_login_id);
          query.bindValue(":loginpass", m_login_Password);



          return query.exec();
}
QSqlQueryModel * Employe::Afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM COMPTE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));


    return model;

}
QSqlQueryModel * Employe::AfficherC()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM EMPLOYES");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_CIN"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
    return model;

}
bool Employe::Supprimer(QString id)
{
    QSqlQuery query;
          query.prepare("DELETE FROM COMPTE WHERE LOGIN_ID =:id");
          query.bindValue(":id",id);
          return query.exec();
}
