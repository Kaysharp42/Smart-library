#ifndef PAIEMENT_H
#define PAIEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qcustomplot.h"
class paiement
{
public:
    paiement();
    paiement(QString,QString,QString,QString,QString);

    void setnump(QString);
    void setdatep(QString);
    void setmontant(QString);
    void settypep(QString);
    void setidpr(QString);

    QString getnump();
    QString getdatep();
    QString getmontant();
    QString gettypep();
    QString getidpr();


    bool ajouter_paiement();
    bool modifier_paiement();
    bool supprimer_paiement();
    QSqlQueryModel * afficher_paiement();

    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);
    QSqlQueryModel * recherche2( int idprod);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
     QSqlQueryModel * afficher_prod();

private:
    QString datep,montant,typep,nump,idpr;

};

#endif // PAIEMENT_H
