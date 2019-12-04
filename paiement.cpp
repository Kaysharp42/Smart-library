#include "paiement.h"

paiement::paiement()
{

}

paiement::paiement(QString a,QString b,QString c,QString d,QString e)
{ nump=a;
  datep=b;
  etatp=c;
  typep=d;
  idp=e;
}

void paiement:: setnump(QString a)
{
  nump=a;
}

void paiement :: setdatep(QString a)
{
    datep=a;
}

void paiement:: setetatp(QString a)
{
    etatp=a;
}
void paiement ::settypep(QString a)
{
    typep=a;
}

void paiement ::setidp(QString a)
{
   idp=a;
}

QString paiement:: getnump()
{
    return nump;
}

QString paiement:: getdatep()
{
    return datep;
}
QString paiement:: getetatp()
{
    return etatp;
}

QString paiement:: gettypep()
{
    return typep;
}

QString paiement:: getidp()
{
    return idp;
}

bool paiement:: ajouter_paiement()
{
    QSqlQuery query;

    query.prepare("INSERT INTO paiement (nump,datep,etatp,typep,idp) " "VALUES  (:nump,:datep,:etatp,:typep,:idp)");
    query.bindValue(":nump",nump);
    query.bindValue(":datep",datep);
    query.bindValue(":etatp",etatp);
    query.bindValue(":typep",typep);
    query.bindValue(":idp", idp);
    return    query.exec();
}
bool paiement:: modifier_paiement()
{
    QSqlQuery query;
       query.prepare("update paiement set datep=:datep,etatp=:etatp,typep=:typep,idp=:idp WHERE nump=:nump");
       query.bindValue(":nump",nump);
       query.bindValue(":datep",datep);
       query.bindValue(":etatp",etatp);
       query.bindValue(":typep",typep);
       query.bindValue(":idp",idp);


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
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etatp"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("typep"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("idp"));

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
       query1.prepare("SELECT datep,etatp,typep,idp FROM paiement WHERE nump=:nump");
       query1.bindValue(":nump",nump);
       query1.exec();
       while(query1.next())
       {
       datep = query1.value(0).toString();
       etatp = query1.value(1).toString();
       typep = query1.value(2).toString();
       idp = query1.value(3).toString();

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
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("etatp"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("typep"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("idp"));

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
