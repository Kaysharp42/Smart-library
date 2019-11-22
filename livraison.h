#ifndef LIVRAISON_H
#define LIVRAISON_H
#include<QString>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QDateEdit>
#include <QDate>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTableView>
#include "connexion.h"
class livraison
{
private:
QString num_liv;
QString date_liv;
QString adresse;
public:

QString getdate_liv(){return date_liv;}
QString getadresse(){return  adresse;}
QString getnum_liv(){return num_liv;}

            void    setdate_liv(QString date_liv){this->date_liv=date_liv;}
            void    setadresse(QString adresse){this->adresse=adresse;}
            void    setnum_liv(QString num_liv){this->num_liv=num_liv;}
    livraison();
    livraison(QString,QString,QString);
    bool ajouterlivraison();
          ~livraison(){}
          QSqlQueryModel* getAlllivraison();
          void deletelivraison(QString num_liv);
          void modifierlivraison(QString num_liv);
          QSqlQueryModel* afficherlivraison() ;
          livraison getlivraison(QString num_liv);
};
#endif // LIVRAISON_H
