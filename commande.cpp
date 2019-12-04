#include "commande.h"
#include "connexion.h"
commande::commande()
{

}
commande::commande(QString c,QString n,QString p,QString m,int nc)
{
    idcmd=c;
    datecmd=n;
    idclient=p;
    idp=m;

    numcmd=nc;

}
void commande::setidcmd(QString c)
{
    idcmd=c;
}
void commande::setdatecmd(QString n)
{
    datecmd=n;
}
void commande::setidclient(QString p)
{
    idclient=p;
}
void commande:: setidp(QString m)
{
    idp=m;
}

void commande::setnumcmd(int n)
{
    numcmd=n;
}
QString commande:: getidcmd()
{
    return  idcmd;
}
QString commande:: getdatecmd()
{
    return datecmd;
}
QString commande:: getidclient()
{
    return idclient;
}
QString commande:: getidp()
{
    return idp;
}

int commande::getnumcmd()
{
    return numcmd;
}
bool commande:: ajouter_commande()
{
    QSqlQuery query;

    query.prepare("INSERT INTO commande (idcmd,datecmd,idclient,idp,numcmd) " "VALUES (:idcmd,:datecmd,:idclient,:idp,:numcmd)");
    query.bindValue(":idcmd",idcmd);
    query.bindValue(":datecmd",datecmd);
    query.bindValue(":idclient",idclient);
    query.bindValue(":idp", idp);
    query.bindValue(":numcmd", numcmd);
    return    query.exec();

}


bool commande::supprimer_commande()
{

    QSqlQuery query;
    query.prepare("Delete from commande where idcmd = :idcmd ");
    query.bindValue(":idcmd",idcmd);
    return    query.exec();

}
QSqlQueryModel * commande:: afficher_commande()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from commande");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idcmd"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("datecmd"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("idclient"));

model->setHeaderData(3, Qt::Horizontal, QObject::tr("idp"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_contart"));
    return model;
}

 bool commande::modifier_commande()
 {      QSqlQuery query;
        query.prepare("update commande set datecmd=:datecmd,idclient=:idclient,idp=:idp,numcmd=:numcmd where idcmd=:idcmd");
        query.bindValue(":idcmd",idcmd);
        query.bindValue(":datecmd",datecmd);
        query.bindValue(":idclient",idclient);
        query.bindValue(":idp", idp);
        query.bindValue(":numcmd", numcmd);
        return    query.exec();

}

QSqlQueryModel * commande:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select idcmd from commande");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idcmd"));
        return model;
}
void commande:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT datecmd,idclient,idp,numcmd FROM commande WHERE idcmd =:idcmd");
     query1.bindValue(":idcmd",idcmd);
     query1.exec();
     while(query1.next())
     {
     datecmd = query1.value(1).toString();
     idclient = query1.value(2).toString();
     idp = query1.value(3).toString();
     numcmd = query1.value(4).toInt();
     }

}
QSqlQueryModel * commande:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM commande WHERE (idcmd LIKE :valeur) order by idcmd");}
    else   { query.prepare("SELECT * FROM commande WHERE (idcmd LIKE :valeur) order by idcmd desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idcmd"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datecmd"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("idclient"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idp"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numcmd"));
    return model;

}
