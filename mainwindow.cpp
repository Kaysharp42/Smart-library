#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include"connexion.h"
#include"commande.h"
#include"livraison.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connexion c ;
    if(c.createconnexion()==true)
        ui->label_2->setText("CONNECTED") ;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked()
{
    QString num_cmd = ui->numcmd1->text();
    QString date_paiement = ui->date1->text() ;
    QString type = ui->type1->text() ;
    int montant = ui->montant1->text().toInt() ;
    paiement R(num_cmd,date_paiement,type,montant) ;
    bool test = R.ajouterpaiement() ;
    if(test == true)
    {
        QMessageBox::information(this,"Saved","Added") ;
    }
    else
    {
        QMessageBox::information(this,"Erreur","Erreur") ;
    }
}
void MainWindow::on_modifier_clicked()
{

    QString num_cmd,date_paiement,type;int montant;
    num_cmd=ui->numcmd2->text();
    date_paiement=ui->date2->text();
    type=ui->type2->text();
    montant=ui->montant2->text().toInt();
    QSqlQuery qry;
    qry.prepare("update paiement set num_cmd='"+num_cmd+"',date_paiement='"+date_paiement+"',type='"+type+"',montant='"+montant+"' where num_cmd='"+num_cmd+"'");
    if(qry.exec())
    QMessageBox::critical(this,tr("Edit"),tr("updated"));
    else
      QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}
void MainWindow::on_afficher_clicked()
{
   paiement *p=new paiement();
   ui->tablepaiement->setModel(p->getAllpaiement());
}

void MainWindow::on_supprimer_clicked()
{
    QString num_cmd,date_paiement,type;
int montant;

    num_cmd=ui->numcmd3->text();
    date_paiement=ui->date3->text();
    type=ui->type3->text();
    montant=ui->montant3->text().toInt();
      QSqlQuery qry;
      qry.prepare("Delete from paiement where num_cmd='"+num_cmd+"'");
      if (qry.exec())
          QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
      else
          QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}
void MainWindow::on_ajouter_liv_clicked()
{
    QString num_liv = ui->num_liv1->text();
    QString date_liv = ui->date_liv1->text() ;
    QString adresse = ui->adresse1->text() ;
    livraison R(num_liv,date_liv,adresse) ;
    bool test = R.ajouterlivraison() ;
    if(test == true)
    {
        QMessageBox::information(this,"Saved","Added") ;
    }
    else
    {
        QMessageBox::information(this,"Erreur","Erreur") ;
    }
}
void MainWindow::on_modifier_liv_clicked()
{

    QString num_liv,date_liv,adresse;
    num_liv=ui->num_liv2->text();
    date_liv=ui->date_liv2->text();
    adresse=ui->adresse2->text();
    QSqlQuery qry;
    qry.prepare("update livraison set num_liv='"+num_liv+"',date_liv='"+date_liv+"',adresse='"+adresse+"',where num_liv='"+num_liv+"'");
    if(qry.exec())
    QMessageBox::critical(this,tr("Edit"),tr("updated"));
    else
      QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}
void MainWindow::on_afficher_liv_clicked()
{
   livraison *p=new livraison();
   ui->tablelivraison->setModel(p->getAlllivraison());
}
void MainWindow::on_supprimer_liv_clicked()
{
    QString num_liv,date_liv,adresse;

    num_liv=ui->num_liv3->text();
    date_liv=ui->date_liv3->text();
    adresse=ui->adresse3->text();
      QSqlQuery qry;
      qry.prepare("Delete from livraison where num_liv='"+num_liv+"'");
      if (qry.exec())
          QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
      else
          QMessageBox::critical(this,tr("error::"),qry.lastError().text());
}

