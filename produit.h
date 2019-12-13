#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QVector>
#include "connexion.h"
#include <QLineEdit>

class Produit
{
private :
    int idProduit;
    QString nom;
    int quantite;
    float prixUnitaire;

public :
    Produit();
    Produit(int idProduit,QString nom,int quantite,float prixUnitaire);

    int getIdProduit(){return idProduit;}




    QSqlQueryModel* AfficherAjouterProduitAucommande(int id);




};
#endif // PRODUIT_H
