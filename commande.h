#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class commande
{
public:
    commande();
    commande(QString,QString,QString,QString,int);
    void setidcmd(QString);
    void setdatecmd(QString);
    void setidclient(QString);
    void setidp(QString);
    void setnumcmd(int);

    QString getidcmd();
    QString getdatecmd();
    QString getidclient();
    QString getidp();
    int getnumcmd();

    bool ajouter_commande();
    bool modifier_commande();
    bool supprimer_commande();
    QSqlQueryModel * afficher_commande();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString idcmd,datecmd,idclient,idp;
    int numcmd;

};

#endif // COMMANDE_H

