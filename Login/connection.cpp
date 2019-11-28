#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("ahmed");//inserer nom de l'utilisateur
db.setPassword("esprit1");//inserer mot de passe de cet utilisateur

if (db.open())
{
    test=true;
}else
 {   throw QString  ("ERROR"+db.lastError().text());}
    return  test;
}
