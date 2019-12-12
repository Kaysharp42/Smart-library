#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableaff->setModel(tmpfournisseur.afficher_fournisseur());

    connexion c;
    c.ouvrirConnexion();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{

    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();

    fournisseur e(cin,nom,prenom,adresse);
    bool test=e.ajouter_fournisseur();
    //QMessageBox msBox;
    if (test)
    {

       // ui->Tab_fournisseur->setModel(attmp.Afficher());

        QMessageBox::information(this,"Ajouter avec succées","pas d erreur");
                      //msBox.exec();
    } else
    {
        QMessageBox::information(this,"ERROR","non ajoute");
                      //msBox.exec();
    }
    ui->tableView_3->setModel(tmpfournisseur.afficher_fournisseur());
}

void MainWindow::on_pushButton_2_clicked()
{
        tmpfournisseur.setnom(ui->lineEdit_nom_2->text());
        tmpfournisseur.setprenom(ui->lineEdit_prenom_2->text());
        tmpfournisseur.setadresse(ui->lineEdit_adresse_2->text());

       // tmpfournisseur.setcin(ui->lineEdit_6->text().toInt());

        bool test=tmpfournisseur.modifier_fournisseur();
        if(test){
                QMessageBox::information(this, "PAS D'ERREUR", " fournisseur modifié");
            }
            else
            {
                QMessageBox::critical(this, " ERREUR ", "fournisseur non modifié ");
            }
        ui->tableaff->setModel(tmpfournisseur.afficher_fournisseur());
}



void MainWindow::on_pushButton_3_clicked()
{


    QString Type =ui->comboBox->currentText() ;
     QMessageBox msBox;
     int cin=ui->lineEdit_cin_rech->text().toInt();
    if(Type =="Standard")
    {
        ui->tableaff->setModel(tmpfournisseur.AfficherTS(cin));

    } else if(Type =="Avancée")
    {
      ui->tableaff->setModel(tmpfournisseur.AfficherTA(cin));
    }
    else
    {
        msBox.setText("ERROR");
                      //msBox.exec();
    }



}

void MainWindow::on_pushButton_4_clicked()
{
    QString cin = ui->nomasup->currentText();
   fournisseur e;
     e.setnom(cin);
   bool test=e.supprimer_fournisseur(cin);
   ui->tableView_2->setModel(tmpfournisseur.afficher_fournisseur());
   QMessageBox msBox;
   if (test)
   {

      // ui->Tab_fournisseur->setModel(attmp.Afficher());

       msBox.setText("Ajouter avec succées");
                     //msBox.exec();
   } else
   {
       msBox.setText("ERROR");
                     //msBox.exec();
   }
    ui->tableaff->setModel(tmpfournisseur.afficher_fournisseur());

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableaff->setModel(tmpfournisseur.AfficherT());

}
void MainWindow::on_ajouter_2_clicked()
{

    int numero=ui->lineEdit_numero->text().toInt();
    int nombre=ui->lineEdit_nombre_3->text().toInt();
    int montant=ui->lineEdit_montant_5->text().toInt();
    int prix=ui->lineEdit_prix->text().toInt();


    commandef c(numero,nombre,montant,prix);
    bool test=c.ajouter_commandef();
    //QMessageBox msBox;
    if (test)
    {

       // ui->Tab_commandef->setModel(attmp.Afficher());

        QMessageBox::information(this,"Ajouter avec succées","pas d erreur");
                      //msBox.exec();
    } else
    {
        QMessageBox::information(this,"ERROR","non ajoute");
                      //msBox.exec();
    }
    ui->tableView_4->setModel(tmpcommandef.afficher_commandef());

}

void MainWindow::on_pushButton_8_clicked()
{
    int numero =  ui->num->currentText().toInt();
   commandef c;
     c.setnumero(numero);
   bool test=c.supprimer_commandef();
   QMessageBox msBox;
   if (test)
   {

      // ui->Tab_fournisseur->setModel(attmp.Afficher());

       msBox.setText("supprimer avec succées");
                     //msBox.exec();
   } else
   {
       msBox.setText("ERROR");
                     //msBox.exec();
   }
   ui->tableView_5->setModel(tmpcommandef.afficher_commandef());
    ui->tableView_7->setModel(tmpcommandef.AfficherT());

}



void MainWindow::on_pushButton_9_clicked()
{
    QString Type =ui->comboBox->currentText() ;
     QMessageBox msBox;
     QString numero=ui->lineEdit_numero_rech_2->text();
    if(Type =="Standard")
    {
        ui->tableaff->setModel(tmpcommandef.AfficherTS(numero));

    } else if(Type =="Avancée")
    {
      ui->tableaff->setModel(tmpcommandef.AfficherTA(numero));
    }
    else
    {
        msBox.setText("ERROR");
                      //msBox.exec();
    }

}


void MainWindow::on_pushButton_6_clicked()
{
    ui->tableaff->setModel(tmpcommandef.AfficherT());
}

void MainWindow::on_pushButton_clicked()
{

    tmpfournisseur.setnom(ui->lineEdit_nom->text());
    tmpfournisseur.setprenom(ui->lineEdit_prenom->text());
    tmpfournisseur.setadresse(ui->lineEdit_adresse->text());

    tmpfournisseur.setcin(ui->lineEdit_cin->text().toInt());

    bool test=tmpfournisseur.modifier_fournisseur();
    if(test){
            QMessageBox::information(this, "PAS D'ERREUR", " fournisseur modifié");
        }
        else
        {
            QMessageBox::critical(this, " ERREUR ", "fournisseur non modifié ");
        }
    ui->tableView_3->setModel(tmpfournisseur.afficher_fournisseur());

}

void MainWindow::on_affichsup_clicked()
{
    ui->tableView_2->setModel(tmpfournisseur.afficher_fournisseur());
     ui->nomasup->setModel(tmpfournisseur.afficher_nomfournisseur());
}

void MainWindow::on_afficher2_clicked()
{
  ui->tableaff->setModel(tmpfournisseur.afficher_fournisseur());
}

void MainWindow::on_modifierc_clicked()
{
    tmpcommandef.setnombre(ui->lineEdit_nombre_3->text().toInt());
    tmpcommandef.setmontant(ui->lineEdit_montant_5->text().toInt());
    tmpcommandef.setprix(ui->lineEdit_prix->text().toInt());


    tmpcommandef.setnumero(ui->lineEdit_numero->text().toInt());

    bool test=tmpcommandef.modifier_commandef();
    if(test){
            QMessageBox::information(this, "PAS D'ERREUR", " commandef modifié");
        }
        else
        {
            QMessageBox::critical(this, " ERREUR ", "commandef non modifié ");
        }
    ui->tableView_4->setModel(tmpcommandef.afficher_commandef());
}

void MainWindow::on_refreshc_clicked()
{
    ui->tableView_5->setModel(tmpcommandef.afficher_commandef());
     ui->num->setModel(tmpcommandef.afficher_numc());
}

void MainWindow::on_affcmd_clicked()
{
    ui->tableView_6->setModel(tmpcommandef.afficher_commandef());
}
