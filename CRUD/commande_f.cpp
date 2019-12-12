#include "commande_f.h"

commande_f::commande_f()
{

}
commande_f::commande_f(int nu,int no,int mo)
{
    numero=nu;
    nombre=no;
    montant=mo;


}
void commande_f::setnumero(int nu)
{
    nombre=nu;
}
void commande_f::setnombre(int no)
{
    nombre=no;
}
void commande_f::setmontant(int mo)
{
    montant=mo;
}


int commande_f:: getnumero()
{
    return  numero;
}
int commande_f:: getnombre()
{
    return nombre;
}
int commande_f:: getmontant()
{
    return montant;
}


bool commande_f:: ajouter_commande_f()
{
    QSqlQuery query;

    query.prepare("INSERT INTO fournisseur (numero,nombre,montant) " "VALUES (:numero,:nombre,:montant)");
    query.bindValue(":nombre",numero);
    query.bindValue(":numero",nombre);
    query.bindValue(":montant",montant);



    return    query.exec();

}
bool commande_f::modifier_commande_f(int numero )
{
    QSqlQuery query;

          query.prepare("UPDATE commande_f  SET  nombre=:nombre , montant=:montant , WHERE numero=:numero  " );
          query.bindValue(":nbr", numero);
           query.bindValue(":id", nombre);
           query.bindValue(":cat", prenom);


          return query.exec();
}

bool commande_f::supprimer_commande_f()
{

    QSqlQuery query;
    query.prepare("Delete from commande_f where numero = :numero ");
    query.bindValue(":numero",numero);
    return    query.exec();

}
QSqlQueryModel * commande_f:: afficher_commande_f()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from commande_f");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));


    return model;
}
QSqlQueryModel * commande_f::AfficherT()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nombre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));

            return model;
}
