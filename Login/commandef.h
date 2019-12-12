#ifndef COMMANDEF_H
#define COMMANDEF_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commandef
{
public:
    commandef();
    commandef(int,int,int,int);
    void setnumero(int);
    void setnombre(int);
    void setmontant(int);
    void setprix(int);

    int getnumero();
    int getnombre();
    int getmontant();
    int getprix();



    bool ajouter_commandef();
    bool modifier_commandef();
    bool supprimer_commandef();
    QSqlQueryModel * afficher_commandef();
    QSqlQueryModel * afficher_numc();
    QSqlQueryModel * AfficherT();
    QSqlQueryModel * AfficherTS(QString);
    QSqlQueryModel * AfficherTA(QString);


private:
    int numero,nombre,montant,prix;
};

#endif // COMMANDEF_H

