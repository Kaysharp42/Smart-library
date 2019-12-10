#ifndef CONTACTS_H
#define CONTACTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Contacts
{
public:
    Contacts();
    Contacts(int, QString,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_profession();
    QString get_email();
    int get_numtel();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * trier ();
    QSqlQueryModel * rechercher(QString);
    bool modifier(Contacts);

private:
    int id, numtel;
    QString nom, prenom, profession, email;

};

#endif // CONTACTS_H
