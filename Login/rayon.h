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
    QSqlQueryModel * Afficher_ETA(QString);
    QSqlQueryModel * Afficher_produit(QString);
    QSqlQueryModel * Afficher_produit_Av(QString);
    QSqlQueryModel * AfficherTrier();
    QSqlQueryModel * AfficherTrierEt();
      QSqlQueryModel *  on_commandLinkButton_modifier_clicked(QString);
    bool Supprimer(int);
    bool modifier(int,int,QString);
    ~Rayon(){}


};

#endif // RAYON_H
