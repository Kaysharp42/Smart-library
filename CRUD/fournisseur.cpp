#include "fournisseur.h"

fournisseur::fournisseur()
{

}
fournisseur::fournisseur(int c,QString n,QString p,QString a)
{
    cin=c;
    nom=n;
    prenom=p;
    adresse=a;

}
void fournisseur::setcin(int c)
{
    cin=c;
}
void fournisseur::setnom(QString n)
{
    nom=n;
}
void fournisseur::setprenom(QString p)
{
    prenom=p;
}
void fournisseur:: setadresse(QString a)
{
    adresse=a;
}

int fournisseur:: getcin()
{
    return  cin;
}
QString fournisseur:: getnom()
{
    return nom;
}
QString fournisseur:: getprenom()
{
    return prenom;
}
QString fournisseur:: getadresse()
{
    return adresse;
}

bool fournisseur:: ajouter_fournisseur()
{
    QSqlQuery query;

    query.prepare("INSERT INTO fournisseur (cin,nom,prenom,adresse) " "VALUES (:cin,:nom,:prenom,:adresse)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

  query.bindValue(":adresse", adresse);


    return    query.exec();

}
bool fournisseur::modifier_fournisseur()
{
    QSqlQuery query;

          query.prepare("UPDATE FOURNISSEUR SET  nom=:nom , prenom=:prenom , adresse=:adresse WHERE cin=:cin  " );
          query.bindValue(":cin", cin);
           query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
           query.bindValue(":adresse", adresse);

          return query.exec();

}

bool fournisseur::supprimer_fournisseur(QString ciin)
{

    QSqlQuery query;
    QString res =ciin;
    query.prepare("DELETE from FOURNISSEUR where nom = :nom ");
    query.bindValue(":nom",res);
    return    query.exec();

}
QSqlQueryModel * fournisseur:: afficher_fournisseur()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}
QSqlQueryModel * fournisseur:: afficher_nomfournisseur()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select nom from fournisseur");


    return model;
}
QSqlQueryModel * fournisseur::AfficherT()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
            return model;
}
QSqlQueryModel * fournisseur::AfficherTS(int)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur where cin = :cin ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
            return model;
}
QSqlQueryModel * fournisseur::AfficherTA(int)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur where cin = :cin ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
            return model;
}
