#include "gestion_rh.h"
#include "ui_gestion_rh.h"
#include "event.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "reclamations.h"
#include <QSound>

Gestion_RH::Gestion_RH(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_RH)
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
       /*animation = new QPropertyAnimation(ui->pb_ajouter, "geometry");
       animation->setDuration(7000);
       animation->setStartValue(ui->pb_ajouter->geometry());
       animation->setEndValue(QRect(300,300,100,50));
       animation->start();*/

       //controle de saisie sur num d event
       ui->lineEdit->setValidator(new QIntValidator(0, 99999, this));

       //music
       player =  new QMediaPlayer(this);
       connect(player, &QMediaPlayer::positionChanged, this, &Gestion_RH::on_position_Changed);
       connect(player, &QMediaPlayer::durationChanged, this, &Gestion_RH::on_duration_Changed);



       //combobox du modifier evenement
       ui->comboBox_3->setModel(tmpevent.afficher());

       //afficher a l'ouverture du programme
       ui->tableView_4->setModel(tmpevent.afficher());
}

Gestion_RH::~Gestion_RH()
{
    delete ui;
}
void Gestion_RH::on_pushButton_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    Event e;
    ui->tableView_4->setModel(e.trier());
}

//Chercher Event
void Gestion_RH::on_pushButton_4_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString cherch = ui->lineEdit_6->text();
    ui->tableView_4->setModel(tmpevent.rechercher(cherch));
}

//MUSIQUE
void Gestion_RH::on_SliderProgress_sliderMoved(int position)
{
    player->setPosition(position);

}

void Gestion_RH::on_sliderVolume_actionTriggered(int position)
{
    player->setVolume(position);

}
//start music
void Gestion_RH::on_pushButton_5_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    //load the file
    player->setMedia(QUrl ::fromLocalFile("C:/Users/sarra_000/Desktop/SVN/trunk/ChirineProjet/music.mp3"));
    player->play();
    qDebug() << player->errorString();

}
//stop music
void Gestion_RH::on_pushButton_7_clicked()
{
    player->stop();

}

void Gestion_RH::on_position_Changed(int position)
{
    ui->SliderProgress->setValue(position);

}

void Gestion_RH::on_duration_Changed(int position)
{
    ui->SliderProgress->setMaximum(position);

}

void Gestion_RH::on_pushButton_11_clicked()
{
}

//rechercher
void Gestion_RH::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->tableView_4->setModel(tmpevent.rechercher(arg1));

}

//EVENEMENTS
//ajouter evenement
void Gestion_RH::on_supprimer_event_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
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



//OK apres avoir choisi le nom de l evenement
void Gestion_RH::on_pushButton_9_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
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

void Gestion_RH::on_pushButton_ModifierEvent_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
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

void Gestion_RH::on_ajouter_event_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    int num= ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_id->text();
    QString type= ui->comboBox_2->currentText();
    QString lieu= ui->lineEdit_14->text();
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

void Gestion_RH::on_quit_ajouter_event_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    this->close();
}





//CONTACTS
//ajouter contact
void Gestion_RH::on_ajouter_event_2_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
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

//supprimer contact
void Gestion_RH::on_supprimer_contact_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
     Clicked.play();
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

//chercher contact
void Gestion_RH::on_lineEdit_11_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(tmpcontact.rechercher(arg1));
}
//chercher contact bouton
void Gestion_RH::on_pushButton_14_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString cherch = ui->lineEdit_11->text();
    ui->tableView_2->setModel(tmpcontact.rechercher(cherch));
}

//RECLAMATIONS

//ajouter reclamation
void Gestion_RH::on_ajouter_rec_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();

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

//supprimer reclamation
void Gestion_RH::on_supprimer_event_2_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
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


void Gestion_RH::on_pushButton_15_clicked(){}
void Gestion_RH::on_pb_ajouter_clicked(){}
void Gestion_RH::on_pb_supprimer_clicked(){}
void Gestion_RH::on_pushButton_2_clicked(){}
void Gestion_RH::on_pushButton_23_clicked(){}
void Gestion_RH::on_pushButton_22_clicked(){}
void Gestion_RH::on_pushButton_24_clicked(){}
void Gestion_RH::on_pushButton_21_clicked(){}
void Gestion_RH::on_pb_supprimer_2_clicked(){}
void Gestion_RH::on_pushButton_8_clicked(){}
void Gestion_RH::on_pushButton_6_clicked(){}
void Gestion_RH::on_sendBtn_clicked(){}


