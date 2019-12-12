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
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));


    return model;

}
QSqlQueryModel * Employe::AfficherC()
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM EMPLOYES");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYES_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("TELEPHONE"));
    return model;

}
bool Employe::Supprimer(QString id)
{
    QSqlQuery query;
          query.prepare("DELETE FROM COMPTE WHERE LOGIN_ID =:id");
          query.bindValue(":id",id);
          return query.exec();
}
bool Employe::Check_Employe_Id(QString id)
{
    QSqlQuery query;
        QString select = "SELECT EMPLOYE_ID FROM EMPLOYES WHERE EMPLOYE_ID=? ";
        query.prepare(select);
        query.addBindValue(id);
     return query.exec();

}
QSqlQueryModel * Employe::Afficher_on_search_bf_delete_clicked(QString id)
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM COMPTE WHERE LOGIN_ID ='"+id+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));
          return model;
}

QSqlQueryModel * Employe::Afficher_on_pushButton_clicked(QString id)
{
    QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM COMPTE WHERE LOGIN_ID ='%"+id+"%'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));
          return model;
}
QSqlQueryModel * Employe::Afficher_on_pushButton_clicked_DESC (QString id )
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMPTE WHERE LOGIN_ID ='"+id+"' ORDER BY LOGIN_ID DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));
          return model;
}
QSqlQueryModel * Employe::Afficher_on_pushButton_clicked_AV_DESC (QString id )
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMPTE WHERE LOGIN_ID LIKE '%"+id+"%' ORDER BY LOGIN_ID DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));
    return model ;
}
QSqlQueryModel * Employe::AfficherC_Ordered ( )
{
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT * FROM EMPLOYES ORDER BY NOM ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYES_ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("TELEPHONE"));
return  model ;

}
