#include "gestion_des_clients.h"
#include "ui_gestion_des_clients.h"
#include "clients.h"
#include "carte_fidelite.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
Gestion_des_clients::Gestion_des_clients(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_des_clients)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->tabetudiant->setModel(tmpetudiant.afficher());
    QPixmap pic(":/img/IMAGE6.jpg");
    //ui->label_6->setPixmap(pic);
    QPixmap pic2(":/img/IMAGE6.jpg");
    ui->label_7->setPixmap(pic2);
    QPixmap pic3(":/img/IMAGE6.jpg");
    ui->label_8->setPixmap(pic3);
}

Gestion_des_clients::~Gestion_des_clients()
{
    delete ui;
}
void Gestion_des_clients::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_prenom_2->text();
  Clients e(id,nom,prenom,adresse);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_des_clients::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpetudiant.supprimer(id);
if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void Gestion_des_clients::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_4->text();
    QString adresse= ui->lineEdit_prenom_3->text();
  Clients e(id,nom,prenom,adresse);
  bool test=e.modifier(id);
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un étudiant"),
                  QObject::tr("Etudiant modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un étudiant"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void Gestion_des_clients::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_5->text().toInt();
    bool test=tmpcartes_fidelite.supprimer(id);
    if(test)
    {ui->tabetudiant_2->setModel(tmpcartes_fidelite.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une carte de fidelite"),
                    QObject::tr("carte de fidelite supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un carte de fidelite"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void Gestion_des_clients::on_pb_ajouter_3_clicked()
{
    int id = ui->lineEdit_idFidA->text().toInt();
    int nombre_points = ui->lineEdit_nombreFidA->text().toInt();
    QString date_debut= ui->lineEdit_dateDFidA->text();
    QString date_expiration= ui->lineEdit_dateEFidA->text();
  carte_fidelite c(id,nombre_points,date_debut,date_expiration);
  bool test=c.ajouter();
  if(test)
{ui->tabetudiant_2->setModel(tmpcartes_fidelite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Carte fidelité"),
                  QObject::tr("Carte fidelité ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Carte fidelité"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_des_clients::on_pb_modifier_2_clicked()
{
    int id = ui->lineEdit_idFidA_2->text().toInt();
    int nombre_points = ui->lineEdit_nombreFidA_2->text().toInt();
    QString date_debut= ui->lineEdit_dateDFidA_2->text();
    QString date_expiration= ui->lineEdit_dateEFid_2->text();
    carte_fidelite c(id,nombre_points,date_debut,date_expiration);
    bool test=c.modifier(id);
  if(test)
{ui->tabetudiant_2->setModel(tmpcartes_fidelite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un étudiant"),
                  QObject::tr("carte fidelite modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un carte fidelite"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}





void Gestion_des_clients::on_Trier2_clicked()
{
    ui->tabetudiant->setModel(tmpetudiant.trier());
}





void Gestion_des_clients::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel();// QSqlQuerryModel permet d afficher
    QSqlQuery query;
    query.prepare("SELECT * FROM clients where prenom like :test ");// Selectionner les prenom qui commencent par la variable entree (test)
    query.bindValue(":test", arg1+"%");// affecter une valeur (arg1°) a une variable (test)
    query.exec(); // executer
    model->setQuery(query);
    ui->tabetudiant->setModel(model);
}

void Gestion_des_clients::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_idFidA->text().toInt();
    int nombre_points = ui->lineEdit_nombreFidA->text().toInt();
    QString date_debut= ui->lineEdit_dateDFidA->text();
    QString date_expiration= ui->lineEdit_dateEFidA->text();
  carte_fidelite c(id,nombre_points,date_debut,date_expiration);
  bool test=c.ajouter();
  if(test)
{ui->tabetudiant_2->setModel(tmpcartes_fidelite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Carte fidelité"),
                  QObject::tr("Carte fidelité ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Carte fidelité"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


