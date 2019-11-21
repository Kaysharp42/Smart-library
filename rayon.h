#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QSqlQueryModel>

class Rayon
{
    int m_Id,m_nbr_etag;

public:
    Rayon();
    Rayon(int,int);
    int Get_Id(){return m_Id;}
    bool Ajouter_Rayon();
    QSqlQueryModel * Afficher();
    bool Supprimer(int);
    bool modifier(int,int);
    ~Rayon(){}


};

#endif // RAYON_H
