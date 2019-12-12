#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString,QString,QString);
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getadresse();


    bool ajouter_fournisseur();
    bool modifier_fournisseur();
    bool supprimer_fournisseur(QString);
    QSqlQueryModel * afficher_fournisseur();
    QSqlQueryModel * afficher_nomfournisseur();
    QSqlQueryModel * AfficherT();
    QSqlQueryModel * AfficherTS(int);
    QSqlQueryModel * AfficherTA(int);


private:
    QString nom,prenom,adresse;
    int cin;
};

#endif // FOURNISSEUR_H
