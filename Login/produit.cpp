#include "produit.h"

Produit::Produit()
{
    this->idProduit=0;
    this->nom="";
    this->quantite=0;
    this->prixUnitaire=0;
}

Produit::Produit(int idProduit,QString nom,int quantite,float prixUnitaire)
{
    this->idProduit=idProduit;
    this->nom=nom;

    this->quantite=quantite;
    this->prixUnitaire=prixUnitaire;
   }



QSqlQueryModel* Produit::AfficherAjouterProduitAucommande(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();


    model->setQuery("SELECT * FROM Produit WHERE id ="+QString::number(id)+"");

    model->setHeaderData(0, Qt::Horizontal , QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal , QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal , QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal , QObject::tr("prixUnitaire"));

    return model;

}

