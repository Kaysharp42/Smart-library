#include "livraison.h"

livraison::livraison()
{

}
livraison::livraison(QString c,QString n,QString p)
{
    idliv=c;
    dateliv=n;
idcmd=p;
}


void livraison::setidliv(QString c)
{
    idliv=c;
}
void livraison::setdateliv(QString n)
{
    dateliv=n;
}
void livraison::setidcmd(QString p)
{
    idcmd=p;
}


QString livraison:: getidliv()
{
    return  idliv;
}
QString livraison:: getdateliv()
{
    return dateliv;
}
QString livraison:: getidcmd()
{
    return idcmd;
}

bool livraison:: ajouter_livraison()
{
    QSqlQuery query;

    query.prepare("INSERT INTO livraison (idliv,dateliv,idcmd) " "VALUES (:idliv,:dateliv,:idcmd)");
    query.bindValue(":idliv",idliv);
    query.bindValue(":dateliv",dateliv);
    query.bindValue(":idclient",idcmd);

    return    query.exec();

}


bool livraison::supprimer_livraison()
{

    QSqlQuery query;
    query.prepare("Delete from livraison where idliv = :idliv ");
    query.bindValue(":idliv",idliv);
    return    query.exec();

}
QSqlQueryModel * livraison:: afficher_livraison()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from livraison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idliv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dateliv"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("idcmd"));


    return model;
}

 bool livraison::modifier_livraison()
 {      QSqlQuery query;
        query.prepare("update livraison set dateliv=:dateliv,idcmd=:idc whermde idliv=:idliv");
        query.bindValue(":idliv",idliv);
        query.bindValue(":dateliv",dateliv);
        query.bindValue(":idclient",idcmd);

        return    query.exec();

}

QSqlQueryModel * livraison:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select idliv from livraison");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idliv"));
        return model;
}
void livraison:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT dateliv,idclient,idp,numliv FROM livraison WHERE idliv =:idliv");
     query1.bindValue(":idliv",idliv);
     query1.exec();
     while(query1.next())
     {
     dateliv = query1.value(1).toString();
     idcmd = query1.value(2).toString();

     }

}
QSqlQueryModel * livraison:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM livraison WHERE (idliv LIKE :valeur) order by idliv");}
    else   { query.prepare("SELECT * FROM livraison WHERE (idliv LIKE :valeur) order by idliv desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idliv"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dateliv"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("idcmd"));

    return model;

}
QSqlQueryModel * livraison ::afficher_c()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select idcmd from commande");


        return model;
}
