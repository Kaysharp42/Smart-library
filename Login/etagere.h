#ifndef ETAGERE_H
#define ETAGERE_H
#include <QString>
#include <QSqlQueryModel>

class Etagere
{
    QString m_etagere_id,m_produit_id;
    int QTT_produit,m_ID,m_num_etage;

public:
    Etagere();
    Etagere(QString,QString,int,int,int);
    Etagere(QString,int);
    bool Ajouter_Produit();
    int Get_Id(){return m_ID;}
    bool Ajouter_Etagere();
    QSqlQueryModel * Afficher();
    bool Supprimer(QString);
    bool modifier_Qtt(int,QString);
    bool modifier_etage(int,QString);
    ~Etagere(){}
};

#endif // ETAGERE_H
