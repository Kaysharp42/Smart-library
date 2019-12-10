#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "reclamations.h"


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
    //QComboBox modifier event
    ui->comboBox_4->addItem("Conference");
    ui->comboBox_4->addItem("Foire");
    ui->comboBox_4 ->addItem("Signature d'un livre");

    //QComboBox type reclamation
    ui->comboBox->addItem("Feedback event");
    ui->comboBox->addItem("Recommandations");
    ui->comboBox->addItem("Reclamations");

    //animation ajouter event
    animation = new QPropertyAnimation(ui->pb_ajouter, "geometry");
    animation->setDuration(7000);
    animation->setStartValue(ui->pb_ajouter->geometry());
    animation->setEndValue(QRect(300,300,100,50));
    animation->start();

    //controle de saisie sur num d event
    ui->lineEdit->setValidator(new QIntValidator(0, 99999, this));

    //music
    player =  new QMediaPlayer(this);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_position_Changed);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_duration_Changed);



    //combobox du modifier evenement
    ui->comboBox_3->setModel(tmpevent.afficher());

    //afficher a l'ouverture du programme
    ui->tableView_4->setModel(tmpevent.afficher());

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
    QDateTime datee=ui->dateTimeEdit_2->dateTime();
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
    Reclamations r(num, titre, redaction);
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

void MainWindow::on_SliderProgress_sliderMoved(int position)
{
    player->setPosition(position);

}

void MainWindow::on_sliderVolume_actionTriggered(int position)
{
    player->setVolume(position);

}

//start music
void MainWindow::on_pushButton_5_clicked()
{
    //load the file
    player->setMedia(QUrl ::fromLocalFile("C:/Users/sarra_000/Desktop/SVN/trunk/ChirineProjet/music.mp3"));
    player->play();
    qDebug() << player->errorString();

}
//stop music
void MainWindow::on_pushButton_7_clicked()
{
    player->stop();

}

void MainWindow::on_position_Changed(int position)
{
    ui->SliderProgress->setValue(position);

}

void MainWindow::on_duration_Changed(int position)
{
    ui->SliderProgress->setMaximum(position);

}

void MainWindow::on_pushButton_6_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_11_clicked()
{
    this->close();
}

//rechercher
void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->tableView_4->setModel(tmpevent.rechercher(arg1));

}

void MainWindow::on_pushButton_8_clicked()
{
    //Smtp *newMail  = new Smtp("chirine.nasri@esprit.tn","chirinenasri13@gmail.com"," Your Subject","My body text");
}

//bech temchi interface mail
/*void MainWindow::on_sendBtn_clicked()
{
    mail m;
    m.exec();
}
*/

//OK apres avoir choisi le nom de l evenement
void MainWindow::on_pushButton_9_clicked()
{
   QString val=ui->comboBox_3->currentText();
   QSqlQuery query;
   query.prepare("select * from EVENT where NOM='"+val+"'");
   if (query.exec())
   {
    while (query.next())
    {
        ui->lineEdit_13->setText(query.value(3).toString());
        QDateTime datee=query.value(4).toDateTime();
        ui->dateTimeEdit_3->setDateTime(datee);
        ui->lineEdit_prenom_2->setText(query.value(2).toString());
    }
   }
}

void MainWindow::on_pushButton_ModifierEvent_clicked()
{
    int num= ui->lineEdit_13->text().toInt();
    QString nom = ui->comboBox_3->currentText();
    QString type= ui->comboBox_4->currentText();
    QString lieu= ui->lineEdit_prenom_2->text();
    QDateTime datee=ui->dateTimeEdit_3->dateTime();
    Event e(num, nom, type, datee, lieu);
    bool test=tmpevent.modifier(e);
    if(test)
      {
        ui->tableView_4->setModel(tmpevent.afficher());
      QMessageBox::information(nullptr, QObject::tr("Modifier un event"),
                    QObject::tr("Event modifie.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

      }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un event"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
