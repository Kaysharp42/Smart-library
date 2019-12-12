#ifndef COMMANDE_F_H
#define COMMANDE_F_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commande_f
{
public:
    commande_f();
    commande_f(int,int,int);
    void setnumero(int);
    void setnombre(int);
    void setmontant(int);

    int getnumero();
    int getnombre();
    int getmontant();


    bool ajouter_commande_f();
    bool modifier_commande_f(int);
    bool supprimer_commande_fr();
    QSqlQueryModel * commande_f();
    QSqlQueryModel * AfficherT();


private:
    int numero,nombre,montant;
};



#endif // COMMANDE_F_H
