#include "Gestion_des_employes.h"
#include "ui_Gestion_des_employes.h"
#include "etudiant.h"
#include "note.h"
#include <QTableView>
#include <QComboBox>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

Gestion_des_employes::Gestion_des_employes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestion_des_employes)
{
ui->setupUi(this);

ui->tabetudiant->setModel(tmpetudiant.afficher());
ui->tabetudiant_2->setModel(tmpnote.afficher());
ui->comboBox_3->setModel(tmpetudiant.afficher());
ui->comboBox_4->setModel(tmpnote.afficher());
ui->combo_supp_note->setModel(tmpnote.afficher());

}

Gestion_des_employes::~Gestion_des_employes()
{
    delete ui;
}

void Gestion_des_employes::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QDateTime datee= ui->dateEdit->dateTime();
    QString fonction= ui->comboBox-> currentText();
    QString sexe= ui->comboBox_2-> currentText();


    ui->comboBox_2->addItem("Femme");
    ui->comboBox_2->addItem("Homme");


    ui-> comboBox->addItem("Responsable Caisse");
    ui-> comboBox->addItem("Responsable Stock");
    ui-> comboBox->addItem("Responsable Rayon");
    ui-> comboBox->addItem("Responsable Fournisseur");

    int tel = ui->lineEdit_6->text().toInt();

  Etudiant e(id,nom,prenom,datee,fonction,sexe,tel);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Employé"),
                  QObject::tr("Employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Gestion_des_employes::on_pb_supprimer_clicked()
{



  int id= ui->comboBox_3-> currentIndex();
QString v=  ui->comboBox_3-> currentText();
int idd=v.toInt();
    ui->comboBox_3->setModel(tmpetudiant.afficher());

bool test=tmpetudiant.supprimer(idd);
int val=tmpetudiant.afficher2();

       
if(val)
        qDebug() << idd;
if(test)
{
    //qDebug() << test;
    ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh

    QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Employé supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un Employé"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Gestion_des_employes::on_pb_ajouter_3_clicked()
{
    int id= ui->comboBox_4-> currentIndex();
  QString v=  ui->comboBox_4-> currentText();
  int idd=v.toInt();
      ui->comboBox_4->setModel(tmpetudiant.afficher());

   int idn = ui->lineEdit_4->text().toInt();
    QDateTime d= ui->dateEdit_2->dateTime();
    QString promotion= ui->lineEdit_10->text();
    int note= ui->lineEdit_11->text().toInt();

    Note n(id,idn,d,promotion,note);
    bool test=n.ajouter2();
    if(test)
    {ui->tabetudiant_2->setModel(tmpnote.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une Note"),
                          QObject::tr("Note ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une Note"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }



void Gestion_des_employes::on_pushButton_clicked()
{
    
/*int id = ui->lineEdit_12->text().toInt();
bool test=tmpnote.supprimer(id);*/

    int idn= ui->combo_supp_note-> currentIndex();
  QString v=  ui->combo_supp_note-> currentText();
  int idnn =v.toInt();
      ui->combo_supp_note->setModel(tmpnote.afficher());

  bool test=tmpnote.supprimer(idnn);
  //int val=tmpnote.afficher2();




if(test)
{ui->tabetudiant_2->setModel(tmpnote.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer une Note"),
                QObject::tr("Note supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une Note"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void Gestion_des_employes::on_pushButton_2_clicked()  //tri

  {ui->tabetudiant->setModel(tmpetudiant.trier());//refresh
  }






void Gestion_des_employes::on_lineEdit_13_textEdited(const QString &arg1)  //recherche avancee
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from etudiant WHERE id like '"+ui->lineEdit_13->text()+"'");
         tmpetudiant.rechercher(q) ;
           q.exec();
           model->setQuery(q);
           ui->tabetudiant->setModel(tmpetudiant.rechercher(q));//refresh
}



