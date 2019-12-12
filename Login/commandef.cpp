#include "commandef.h"
#include <QString>

commandef::commandef()
{

}
commandef::commandef(int num,int nom,int mon, int p)
{
    numero=num;
    nombre=nom;
    montant=mon;
    prix=p;


}
void commandef::setnumero(int num)
{
    numero=num;
}
void commandef::setnombre(int nom)
{
    nombre=nom;
}
void commandef::setmontant(int mon)
{
    montant=mon;
}
void commandef::setprix(int p)
{
     prix=p;
}


int commandef:: getnumero()
{
    return  numero;
}
int commandef:: getnombre()
{
    return nombre;
}
int commandef:: getmontant()
{
    return montant;
}
int commandef:: getprix()
{
    return prix;
}


bool commandef:: ajouter_commandef()
{
    QSqlQuery query;

    query.prepare("INSERT INTO commandef (numero,nombre,montant,prix) " "VALUES (:numero,:nombre,:montant,:prix)");
    query.bindValue(":numero",numero);
    query.bindValue(":nombre",nombre);
    query.bindValue(":montant",montant);
    query.bindValue(":prix",prix);




    return    query.exec();

}
bool commandef::modifier_commandef()
{
    QSqlQuery query;

          query.prepare("UPDATE COMMANDEF SET  nombre=:nombre , montant=:montant , prix=:prix  WHERE numero=:numero " );
          query.bindValue(":numero", numero);
           query.bindValue(":nombre", nombre);
           query.bindValue(":montant", montant);
           query.bindValue(":prix",prix);


          return query.exec();

}

bool commandef::supprimer_commandef()
{

    QSqlQuery query;
    query.prepare("Delete from commandef where numero = :numero ");
    query.bindValue(":numero",numero);
    return    query.exec();

}
QSqlQueryModel * commandef:: afficher_commandef()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from commandef");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


    return model;
}
QSqlQueryModel * commandef::AfficherT()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from commandef order by nombre");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
            return model;
}

QSqlQueryModel * commandef::AfficherTS(QString numero)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from commandef where numero ='"+numero+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
            return model;
}
QSqlQueryModel * commandef::AfficherTA(QString numero)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from commandef where cin ='"+numero+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

            return model;
}
QSqlQueryModel * commandef:: afficher_numc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select numero from commandef");


    return model;
}
