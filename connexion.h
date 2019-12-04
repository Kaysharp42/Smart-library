#ifndef CONNEXION_H
#define CONNEXION_H
#include <QMainWindow>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QFileInfo>
#include<QtSql/QSqlError>

class connexion
{


private :
    QSqlDatabase mydb ;
public :
    bool CreatConnexion() ;

} ;
#endif // CONNEXION_H
