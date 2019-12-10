#ifndef RECLAMATIONS_H
#define RECLAMATIONS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>

class Reclamations
{
public:
    Reclamations();
    Reclamations(int, QString, QString);
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


#endif // RECLAMATIONS_H
