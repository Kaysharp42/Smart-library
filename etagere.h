#ifndef ETAGERE_H
#define ETAGERE_H
#include <QString>
#include <QSqlQueryModel>

class Etagere
{
    QString m_etagere_id,m_produit_id;
    int QTT_produit,m_ID;

public:
    Etagere();
    Etagere(QString,int);
    int Get_Id(){return m_ID;}
    bool Ajouter_Etagere();
    QSqlQueryModel * Afficher();
    bool Supprimer(QString);

    ~Etagere(){}
};

#endif // ETAGERE_H
