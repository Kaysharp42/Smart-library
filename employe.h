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
    bool Supprimer(QString);
    ~Employe(){}

};

#endif // EMPLOYE_H


