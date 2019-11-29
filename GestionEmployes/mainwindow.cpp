#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "note.h"
#include <QTableView>

#include <QMessageBox>
#include <QDate>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

ui->tabetudiant->setModel(tmpetudiant.afficher());
ui->tabetudiant_2->setModel(tmpnote.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QDateTime datee= ui->dateEdit->dateTime();
    QString sexe= ui->lineEdit_5->text();
    QString fonction= ui->lineEdit_4-> text();
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

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_8->text().toInt();
bool test=tmpetudiant.supprimer(id);
if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Employé supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un Employé"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_3_clicked()
{
    int id = ui->lineEdit_9->text().toInt();
    QDateTime d= ui->dateEdit_2->dateTime();
    QString promotion= ui->lineEdit_10->text();
    int note= ui->lineEdit_11->text().toInt();

    Note n(id,d,promotion,note);
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



void MainWindow::on_pushButton_clicked()
{
int id = ui->lineEdit_12->text().toInt();
bool test=tmpnote.supprimer(id);
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

void MainWindow::on_pushButton_2_clicked()

  {ui->tabetudiant->setModel(tmpetudiant.trier());//refresh
  }








void MainWindow::on_lineEdit_13_textEdited( QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from etudiant WHERE id like '%id' ");
            q.addBindValue("%"+id+"%");
           q.exec();
           //q.next();
           model->setQuery(q);



}



void MainWindow::on_pushButton_3_clicked()
{
    QString cherch = ui->lineEdit_13->text();
        ui->tabetudiant->setModel(tmpetudiant.rechercher(cherch));
    }

