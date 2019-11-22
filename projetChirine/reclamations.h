#ifndef RECLAMATIONS_H
#define RECLAMATIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qcombobox>

class Reclamations
{
public:
    Reclamations();
    Reclamations(int, QString, QString, QString);
    int get_num();
    QString get_titre();
    QString get_redacteur();
    QString get_destinataire();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);


private:
    int num;
    QString titre, redacteur, destinataire;
    QComboBox type;
};

#endif // RECLAMATIONS_H

