#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "reclamation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSystemTrayIcon= new QSystemTrayIcon (this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico"));
    mSystemTrayIcon->setVisible(true);
    mSystemTrayIcon->showMessage("Message", "montrer message", QIcon(":/myappico"), 3000 );

    //QComboBox type event
    ui->comboBox_2->addItem("Conference");
    ui->comboBox_2->addItem("Foire");
    ui->comboBox_2->addItem("Signature d'un livre");

    //QComboBox type reclamation
    ui->comboBox->addItem("Feedback event");
    ui->comboBox->addItem("Recommandations");
    ui->comboBox->addItem("Reclamations");

    //animation ajouter event
    animation = new QPropertyAnimation(ui->pushButton_24, "geometry");
    animation->setDuration(7000);
    animation->setStartValue(ui->pushButton_24->geometry());
    animation->setEndValue(QRect(300,300,100,50));
    animation->start();

    //controle de saisie sur num d event
    ui->lineEdit->setValidator(new QIntValidator(0, 99999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajouter evenement
void MainWindow::on_pb_ajouter_clicked()
{
    int num= ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_id->text();
    QString type= ui->comboBox_2->currentText();
    QString lieu= ui->lineEdit_prenom->text();
    int datee=ui->dateEdit->text().toInt();
    Event e(num, nom, type, datee, lieu);
    bool test=e.ajouter();
    if(test)
    {
      ui->tableView_4->setModel(tmpevent.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter un event"),
                  QObject::tr("Event ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un event"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

//supprimer event
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

//Trier evenements
void MainWindow::on_pushButton_clicked()
{
    Event e;
    ui->tableView_4->setModel(e.trier());
}

//trier evenements
void MainWindow::on_pushButton_2_clicked()
{
    Event e;
    ui->tableView_4->setModel(e.trier());
}

//Chercher Event
void MainWindow::on_pushButton_4_clicked()
{
    QString cherch = ui->lineEdit_6->text();
    ui->tableView_4->setModel(tmpevent.rechercher(cherch));
}




//fermer ajouter reclamation
void MainWindow::on_pushButton_23_clicked()
{
    this->close();
}

//supprimer reclamation
void MainWindow::on_pushButton_15_clicked()
{
    int num = ui->lineEdit_id_6->text().toInt();
    bool test=tmprec.supprimer(num);
    if(test)
    {
        ui->tableView_3->setModel(tmprec.afficher()); //refresh
        /*QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Reclamation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

//ajouter reclamation
void MainWindow::on_pushButton_24_clicked()
{

    int num= ui->lineEdit_3->text().toInt();
    QString titre = ui->lineEdit_10->text();
    QString redaction= ui->lineEdit_12->text();
    Reclamation r(num, titre, redaction);
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


//ajouter contacts
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

/*
 * //QMessageBox::aboutQt(this, tr("about QT"));
    if (QSystemTrayIcon::isSystemTrayAvailable() == false)
    {
        QMessageBox::critical(nullptr, QObject::tr("Afficher message"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Afficher message"),
                    QObject::tr("OKKKKKKKKKKK !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    mSystemTrayIcon->showMessage("Message", "montrer message", QIcon(":/myappico"), 3000 );
 */
