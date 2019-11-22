#ifndef PAIEMENT_H
#define PAIEMENT_H
#include<QString>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QDateEdit>
#include <QDate>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTableView>
#include "connexion.h"


class paiement
{
private:
private :
    QString num_cmd  ;
    QString date_paiement ;
    QString  type ;
    int montant ;
public:
    QString getnum_cmd(){return num_cmd;}
    QString gettype(){return type;}
    QString getdate_paiement(){return  date_paiement;}
    int     getmontant(){return montant;}

    void    setnum_cmd(QString num_cmd){this->num_cmd=num_cmd;}
    void    settype(QString type){this->type=type;}
    void    setdate_paiement(QString date_paiement){this->date_paiement=date_paiement;}
    void    setmontant(int montant){this->montant=montant;}

    paiement();
    paiement(QString ,QString ,QString,int) ;
     bool ajouterpaiement();
           ~paiement(){}
           QSqlQueryModel* getAllpaiement();
           void deletepaiement(QString num_cmd);
           void modifierpaiement(QString num_cmd);
           QSqlQueryModel* afficherpaiement() ;
           paiement getpaiement(QString num_cmd);
           void ImprimerListepaiement(QTableView* table_paiement);
};

#endif // PAIEMENT_H
