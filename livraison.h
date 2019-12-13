#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <QString>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
class livraison
{
public:
    livraison();
    livraison(QString,QString,QString);
    void setidliv(QString);
    void setdateliv(QString);
    void setidcmd(QString);


    QString getidliv();
    QString getdateliv();
    QString getidcmd();


    bool ajouter_livraison();
    bool modifier_livraison();
    bool supprimer_livraison();
    QSqlQueryModel * afficher_livraison();
    QSqlQueryModel * afficher_list();
     QSqlQueryModel * afficher_c();
    void chercher();
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString idliv,dateliv,idcmd;


};

#endif // LIVRAISON_H
