#ifndef RECLAMATION_H
#define RECLAMATION_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>

class Reclamation
{
public:
    Reclamation();
    Reclamation(int, QString, QString);
    int get_num();
    QString get_titre();
    QString get_redacteur();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);


private:
    int num;
    QString titre, redacteur, destinataire;
    QComboBox type;
};


#endif // RECLAMATION_H
