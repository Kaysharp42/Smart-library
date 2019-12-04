#ifndef PAIEMENT_H
#define PAIEMENT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "qcustomplot.h"
class paiement
{
public:
    paiement();
    paiement(QString,QString,QString,QString,QString);

    void setnump(QString);
    void setdatep(QString);
    void setetatp(QString);
    void settypep(QString);
    void setidp(QString);

    QString getnump();
    QString getdatep();
    QString getetatp();
    QString gettypep();
    QString getidp();

    bool ajouter_paiement();
    bool modifier_paiement();
    bool supprimer_paiement();
    QSqlQueryModel * afficher_paiement();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);

private:
    QString datep,etatp,typep,idp, nump;

};

#endif // PAIEMENT_H
