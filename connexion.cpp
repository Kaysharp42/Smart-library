#include "connexion.h"
#include <QDebug>
#include <QtSql/QSqlError>

bool connexion::createconnexion()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE") ;
    mydb.setDatabaseName("prosit");
    mydb.setUserName("youssef02");
    mydb.setPassword("esprit18");

    if(mydb.open())
    {

        return true ;



qDebug()<<mydb.lastError().text();
    }

     return false ;


}
