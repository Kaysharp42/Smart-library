#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>

class Employe
{
    QString  m_Id,m_login_Password,m_login_id;

public:
    Employe();
    Employe(QString,QString,QString);
    QString Get_Id(){return m_Id;}
    bool Ajouter_Employe();
  // QSqlQueryModel afficher();
    QSqlQueryModel * Afficher();
    QSqlQueryModel * AfficherC();
    QSqlQueryModel * AfficherC_Ordered();
    bool Supprimer(QString);
    bool Check_Employe_Id(QString);
    QSqlQueryModel * Afficher_on_search_bf_delete_clicked(QString);
    QSqlQueryModel * Afficher_on_pushButton_clicked (QString) ;
    QSqlQueryModel * Afficher_on_pushButton_clicked_DESC (QString) ;
    QSqlQueryModel * Afficher_on_pushButton_clicked_AV_DESC (QString) ;

    ~Employe(){}

};

#endif // EMPLOYE_H


