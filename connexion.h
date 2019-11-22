#ifndef CONNEXION_H
#define CONNEXION_H
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>

class connexion
{
private:
    QSqlDatabase mydb ;
public:
    bool createconnexion();
};

#endif // CONNEXION_H
