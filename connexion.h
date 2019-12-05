#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QMainWindow>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_H
