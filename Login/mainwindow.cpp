#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "contacts.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajouter evenement
void MainWindow::on_pb_ajouter_clicked()
{
        int num= ui->lineEdit_10->text().toInt();
        QString nom = ui->lineEdit_id->text();
        QString type= ui->lineEdit_nom->text();
        QString lieu= ui->lineEdit_prenom->text();
        Event e(num, nom, type, lieu);
      bool test=e.ajouter();
      if(test)
    {ui->tableView_4->setModel(tmpevent.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un event"),
                      QObject::tr("Event ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un event"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

//supprimer un evenement
void MainWindow::on_pb_supprimer_clicked()
{
int num = ui->lineEdit_id_2->text().toInt();
bool test=tmpevent.supprimer(num);
if(test)
{ui->tableView_4->setModel(tmpevent.afficher()); //refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un évenement"),
                QObject::tr("Evenement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un évenement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

//ajouter contact
void MainWindow::on_pushButton_21_clicked()
{
    int id= ui->lineEdit_2->text().toInt();
    QString nom = ui->lineEdit_4->text();
    QString prenom= ui->lineEdit_5->text();
    QString profession= ui->lineEdit_7->text();
    QString email= ui->lineEdit_8->text();
    int numTel= ui->lineEdit_9->text().toInt();
    Contacts c(id, nom, prenom, profession, email, numTel);
  bool test=c.ajouter();
  if(test)
    {ui->tableView_2->setModel(tmpcontact.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un contact"),
                  QObject::tr("Contact ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un contact"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

//ajouter reclamation
void MainWindow::on_pushButton_23_clicked()
{
    int num= ui->lineEdit_3->text().toInt();
    QString titre = ui->lineEdit_10->text();
    QString redaction= ui->lineEdit_12->text();
    QString destinataire= ui->lineEdit_13->text();
    Reclamations r(num, titre, redaction, destinataire);
  bool test=r.ajouter();
  if(test)
    {ui->tableView_3->setModel(tmprec.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                  QObject::tr("Reclamation ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

//supprimer reclamation
void MainWindow::on_pb_supprimer_3_clicked()
{
    int num = ui->lineEdit_id_6->text().toInt();
    bool test=tmprec.supprimer(num);
    if(test)
    {ui->tableView_3->setModel(tmprec.afficher()); //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Reclamation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

//supprimer contacts
void MainWindow::on_pb_supprimer_2_clicked()
{
    int num = ui->lineEdit_id_4->text().toInt();
    bool test=tmpcontact.supprimer(num);
    if(test)
    {ui->tableView_2->setModel(tmpcontact.afficher()); //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un contact"),
                    QObject::tr("Contact supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un contact"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
