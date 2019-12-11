#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class carte_fidelite
{
public:
    carte_fidelite();
    carte_fidelite(int,int,QString,QString);
    QString get_date_expiration();
    QString get_date_debut();
    int get_id();
    int get_nombre_points();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int id;
    int nombre_points;
    QString date_expiration;
    QString date_debut;
};

#endif // CARTE_FIDELITE_H
