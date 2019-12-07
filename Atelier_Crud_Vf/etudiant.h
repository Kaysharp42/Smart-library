#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Clients
{public:
    Clients();
    Clients(int,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,prenom,adresse;
    int id;
};

#endif // ETUDIANT_H
