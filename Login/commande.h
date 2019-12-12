#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commande
{
public:
    commande();
    commande(QString,QString,QString,QString);
    void setidcmd(QString);
    void setdatecmd(QString);
    void setidclient(QString);
    void setidp(QString);


    QString getidcmd();
    QString getdatecmd();
    QString getidclient();
    QString getidp();


    bool ajouter_commande();
    bool modifier_commande();
    bool supprimer_commande();
    QSqlQueryModel * afficher_commande();
    QSqlQueryModel * afficher_client();
     QSqlQueryModel * afficher_p();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString idcmd,datecmd,idclient,idp;


};

#endif // COMMANDE_H
