#include "connexion.h"
bool connexion::CreatConnexion()
{
   mydb = QSqlDatabase::addDatabase("QOCI") ;
   mydb.setDatabaseName("prosit");
   mydb.setUserName("youssef02");
   mydb.setPassword("esprit18");

   if(mydb.open())
   {

       return true ;




   }
   else
    return false ;
}
