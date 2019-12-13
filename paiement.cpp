#include "paiement.h"

paiement::paiement()
{

}

paiement::paiement(QString a,QString b,QString c,QString d,QString e)
{ nump=a;
  datep=b;
  montant=c;
  typep=d;
  idpr=e;

}

void paiement:: setnump(QString a)
{
  nump=a;
}

void paiement :: setdatep(QString b)
{
    datep=b;
}

void paiement::setmontant(QString c)
{
    montant=c;
}
void paiement ::settypep(QString d)
{
    typep=d;
}
void paiement::setidpr(QString e)
{idpr=e;}
QString paiement:: getnump()
{
    return nump;
}

QString paiement:: getdatep()
{
    return datep;
}
QString paiement:: getmontant()
{
    return montant;
}

QString paiement:: gettypep()
{
    return typep;
}
QString paiement::getidpr()
{return idpr;}


bool paiement:: ajouter_paiement()
{
    QSqlQuery query;

    query.prepare("INSERT INTO paiement (nump,datep,montant,typep,idpr) " "VALUES  (:nump,:datep,:montant,:typep,:idpr)");
    query.bindValue(":nump",nump);
    query.bindValue(":datep",datep);
    query.bindValue(":montant",montant);
    query.bindValue(":typep",typep);
    query.bindValue(":idpr",idpr);

    return    query.exec();
}
bool paiement:: modifier_paiement()
{
    QSqlQuery query;
       query.prepare("update paiement set datep=:datep,montant=:montant,typep=:typep,idpr=:idpr WHERE nump=:nump");
       query.bindValue(":nump",nump);
       query.bindValue(":datep",datep);
       query.bindValue(":etatp",montant);
       query.bindValue(":typep",typep);
       query.bindValue(":idpr",idpr);
       return    query.exec();

}
bool paiement:: supprimer_paiement()
{
    QSqlQuery query;
    query.prepare("Delete from paiement where nump = :nump ");
    query.bindValue(":nump",nump);
    return    query.exec();
}
QSqlQueryModel * paiement ::afficher_paiement()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from paiement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nump"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datep"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("typep"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("idpr"));


        return model;
}
QSqlQueryModel * paiement:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select nump from paiement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nump"));


            return model;

}
void paiement:: chercher()
{
    QSqlQuery query1;
       query1.prepare("SELECT datep,montant,typep,idpr FROM paiement WHERE nump=:nump");
       query1.bindValue(":nump",nump);
       query1.exec();
       while(query1.next())
       {
       datep = query1.value(0).toString();
       montant = query1.value(1).toString();
       typep = query1.value(2).toString();
       idpr = query1.value(3).toString();

          }
}
QSqlQueryModel * paiement:: recherche(QString valeur, int etat)
{    QSqlQueryModel * model=new QSqlQueryModel();

     QSqlQuery query;
     if(etat==0)
           { query.prepare("SELECT * FROM paiement WHERE (nump  like :valeur) order by nump");}
     else  { query.prepare("SELECT * FROM paiement WHERE (nump like :valeur) order by nump desc");}
     valeur="%"+valeur+"%";
     query.bindValue(":valeur",valeur);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("nump"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("datep"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("typep"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("idpr"));


     return model;

}

 void paiement:: statistique(QVector<double>* ticks,QVector<QString> *labels)
 {  QSqlQuery q;
     int i=0;
     q.exec("select typep from paiement");
     while (q.next()) {
         QString typep = q.value(0).toString();
         i++;
         *ticks<<i;
         *labels <<typep;
 }

 }
 QSqlQueryModel * paiement ::afficher_prod()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select id from produit");


         return model;
 }
 QSqlQueryModel * paiement:: recherche2( int idprod)
 {    QSqlQueryModel * model=new QSqlQueryModel();

      QSqlQuery query;
        QSqlQuery query2;

             query.prepare("SELECT * FROM paiement WHERE (idpr  like :idprod) ");
    query2.prepare("SELECT * FROM PAIEMENT INNER JOIN PRODUIT ON PAIEMENT.idpr = PRODUIT.id;");

      query.bindValue(":idprod",idprod);
      query.exec();
      model->setQuery(query2);
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("nump"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("datep"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("typep"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("idpr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
      /* query2.bindValue(":idprod",idprod);
       query2.exec();
        model->setQuery(query2);
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));*/


      return model;

 }


