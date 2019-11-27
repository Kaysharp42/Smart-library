#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QSqlQueryModel>

class Rayon
{
    int m_Id,m_nbr_etag;
    QString m_Categorie;
public:
    Rayon();
    Rayon(int,int,QString);
    int Get_Id(){return m_Id;}
    bool Ajouter_Rayon();
    QSqlQueryModel * Afficher();
    QSqlQueryModel * AfficherTrier();
    QSqlQueryModel * AfficherTrierEt();
    bool Supprimer(int);
    bool modifier(int,int,QString);
    ~Rayon(){}


};

#endif // RAYON_H
