#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("melissa");//inserer nom de l'utilisateur
db.setPassword("melissa");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;

    return  test;
}
