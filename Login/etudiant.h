#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>



class Etudiant
{public:
    Etudiant();
    Etudiant(int,QString,QString,QDateTime,QString,QString,int);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QDateTime get_datee();
    QString get_fonction();
    QString get_sexe();
    int get_tel();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * trier ();
    QSqlQueryModel *rechercher(QSqlQuery);
      int afficher2();





private:
    QString nom,prenom,fonction,sexe;

    QDateTime datee;

    int id, tel;
};

#endif // ETUDIANT_H
