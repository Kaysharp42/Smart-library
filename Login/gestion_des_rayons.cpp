#include "gestion_des_rayons.h"
#include "ui_gestion_des_rayons.h"
#include "rayon.h"
#include "etagere.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
#include "login.h"
#include <QDebug>
#include <QSound>
#include <windows.h>
#include <QTimer>
#include <QTime>

//using namespace QtCharts;
Gestion_des_Rayons::Gestion_des_Rayons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_des_Rayons)
{
    ui->setupUi(this);
    timer_1s = new QTimer(this);
        QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
        timer_1s->start(1000);
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_idrayon->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tableView_ajouter->setModel(r.Afficher());
    ui->tableView_etage->setModel(E.Afficher());
    ui->tableView_rayon->setModel(r.Afficher());
    ui->tableView_etage_2->setModel(E.Afficher());
}

Gestion_des_Rayons::~Gestion_des_Rayons()
{
    delete ui;
}

void Gestion_des_Rayons::UpdateTime()
{
    ui->lbl_time_6->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void Gestion_des_Rayons::on_commandLinkButton_7_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(0);

}
void Gestion_des_Rayons::on_commandLinkButton_Ajouet_Rayon_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
   ui->tableView_ajouter->setModel(r.Afficher());
      ui->tableView_ajouter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int id=ui->lineEdit_idrayon->text().toInt();
    int nbr=ui->lineEdit_nbr->text().toInt();
   QString cat =ui->comboBox_cat->currentText();
    Rayon R(id,nbr,cat);
    bool test=R.Ajouter_Rayon();
    QMessageBox msBox;
    if (test)
    {
        ui->tableView_ajouter->setModel(r.Afficher());
        ui->tableView_ajouter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       // ui->Tab_Etudiant->setModel(attmp.Afficher());

        msBox.setText("Ajouter avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
}


void Gestion_des_Rayons::on_commandLinkButton_Annuler_ajout_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_commandLinkButton_modifier_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->tableView_modifier->setModel(r.Afficher());
       ui->tableView_modifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
int id=ui->lineEdit_id_modif->text().toInt();
int nbr=ui->lineEdit_4->text().toInt();
QString Categorie = ui->comboBox_new_Categ->currentText();
Rayon r;
bool test=r.modifier(id,nbr,Categorie);
QMessageBox msBox;

if (test)
{

    ui->tableView_modifier->setModel(r.Afficher());
    ui->tableView_modifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   // ui->Tab_Etudiant->setModel(attmp.Afficher());

    msBox.setText("Ajouter avec succées");
                  msBox.exec();
} else
{
    msBox.setText("ERROR");
                  msBox.exec();
}
}

void Gestion_des_Rayons::on_commandLinkButton_annuler_modfi_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_commandLinkButton_Supprimer_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_supp->setModel(model);
    ui->tableView_supp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Rayon r;
    int id=ui->lineEdit_6->text().toInt();
    bool test=r.Supprimer(id);
     QMessageBox msBox;
    if(test)
    {
        msBox.setText("Supprimer avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
          model->setQuery("SELECT * FROM RAYON WHERE ID ='"+ui->lineEdit_6->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_ETAGERE"));
    ui->tableView_supp->setModel(model);
    ui->tableView_supp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_commandLinkButton_annuler_supp_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_pushButton_recherc_supp_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_supp->setModel(model);
    ui->tableView_supp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



          model->setQuery("SELECT * FROM RAYON WHERE ID ='"+ui->lineEdit_6->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_ETAGERE"));

    ui->tableView_supp->setModel(model);
    ui->tableView_supp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_pushButton_recher_modifier_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_modifier->setModel(model);
    ui->tableView_modifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



          model->setQuery("SELECT * FROM RAYON WHERE ID ='"+ui->lineEdit_id_modif->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_ETAGERE"));
    ui->tableView_modifier->setModel(model);
    ui->tableView_modifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_pushButton_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    this->close();
    //LogIn().show();
}

void Gestion_des_Rayons::on_commandLinkButton_ajouter_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    int r_id=ui->lineEdit_rayonid->text().toInt();
    QString e_id=ui->lineEdit_etageid->text();
       qDebug() << r_id ;
    Etagere E(e_id,r_id);
    bool test=E.Ajouter_Etagere();
    QMessageBox msBox;

    if (test)
    {
        ui->tableView_etage->setModel(E.Afficher());
        ui->tableView_etage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       // ui->Tab_Etudiant->setModel(attmp.Afficher());

        msBox.setText("Ajouter avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
}


void Gestion_des_Rayons::on_commandLinkButton_annuler_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
        ui->stackedWidget->setCurrentIndex(0);
}

void Gestion_des_Rayons::on_pushButton_2_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
          model->setQuery("SELECT * FROM ETAGERE WHERE ETAGERE_ID ='"+ui->lineEdit_etageSupp->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ETAGERE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTT_PRODUIT"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_ETAGE"));
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_commandLinkButton_5_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Rayon r;
    QString e_id =ui->lineEdit_etageSupp->text();
    bool test=E.Supprimer(e_id);
     QMessageBox msBox;
    if(test)
    {
        msBox.setText("Supprimer avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
    model->setQuery("SELECT * FROM ETAGERE WHERE ETAGERE_ID ='"+ui->lineEdit_etageSupp->text()+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ETAGERE_ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT_ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTT_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_ETAGE"));
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void Gestion_des_Rayons::on_commandLinkButton_A_R_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
        Clicked.play();
        if ( Clicked.isFinished())
        {
        ui->stackedWidget->setCurrentIndex(1);
        }

}

void Gestion_des_Rayons::on_commandLinkButton_M_R_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(2);

}

void Gestion_des_Rayons::on_commandLinkButton_S_R_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(3);

}

void Gestion_des_Rayons::on_commandLinkButton_A_E_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(5);

}

void Gestion_des_Rayons::on_commandLinkButton_S_E_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(6);

}

void Gestion_des_Rayons::on_commandLinkButton_AF_F_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(4);

}


void Gestion_des_Rayons::on_commandLinkButton_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_pushButton_Add_new_Product_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    int R_id=ui->lineEdit_Rayon_Id_Produit->text().toInt();
    int QTT=ui->lineEdit_QTT_Produit->text().toInt();
    int Num=ui->lineEdit_num_etage_produit->text().toInt();
    QString etage_id = ui->lineEdit_Etage_Id_Produit->text();
    QString produit_id =ui->lineEdit_Produit_Id->text();
    Etagere E (etage_id,produit_id,R_id,QTT,Num);
    bool test=E.Ajouter_Produit();
    qDebug()<<test;
    QMessageBox msBox;

    if (test)
    {
        ui->tableView_rayon->setModel(r.Afficher());
        ui->tableView_etage_2->setModel(E.Afficher());
        ui->tableView_etage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        msBox.setText("Ajouter avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
}

void Gestion_des_Rayons::on_pushButton_Mod_Product_Qtt_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString p_id =ui->lineEdit_Produit_Id_to_modifier->text();
    int Qtt=ui->lineEdit_new_qtt->text().toInt();
    Etagere e;
    bool test=e.modifier_Qtt(Qtt,p_id);
    QMessageBox msBox;

    if (test)
    {
        ui->tableView_rayon->setModel(r.Afficher());
        ui->tableView_etage_2->setModel(E.Afficher());
        ui->tableView_etage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        msBox.setText("Ajouter avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
}

void Gestion_des_Rayons::on_pushButton_Mod_Product_num_etage_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString p_id =ui->lineEdit_Produit_Id_to_modifier->text();
    int etage=ui->lineEdit_num_etage_produit->text().toInt();
    Etagere e;
    bool test=e.modifier_etage(etage,p_id);
    QMessageBox msBox;

    if (test)
    {
        ui->tableView_rayon->setModel(r.Afficher());
        ui->tableView_etage_2->setModel(E.Afficher());
        ui->tableView_etage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        msBox.setText("Ajouter avec succées");
                      msBox.exec();
    } else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }
}

void Gestion_des_Rayons::on_commandLinkButton_rech_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void Gestion_des_Rayons::on_pushButton_3_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QString Type =ui->comboBox_type_rec_pr->currentText() ;
     QMessageBox msBox;
    if(Type =="Standard")
    {
        qDebug()<<Type;
        model->setQuery("SELECT * FROM PRODUIT WHERE PRODUIT_ID ='"+ui->lineEdit_rech_prod->text()+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRODUIT_ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT"));
        ui->tableView_produit->setModel(model);
        ui->tableView_produit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else if(Type =="Avancée")
    {
        qDebug()<<Type;

        model->setQuery("SELECT * FROM PRODUIT WHERE PRODUIT_ID LIKE '%"+ui->lineEdit_rech_prod->text()+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRODUIT_ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT"));
        ui->tableView_produit->setModel(model);
        ui->tableView_produit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }else
    {
        msBox.setText("ERROR");
                      msBox.exec();
    }

}
void Gestion_des_Rayons::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void Gestion_des_Rayons::on_pushButton_order_clicked()
{
    ui->tableView_ajouter->setModel(r.AfficherTrier());
}

void Gestion_des_Rayons::on_pushButton_trier_clicked()
{
    ui->tableView_rayon->setModel(r.AfficherTrier());
    ui->tableView_etage_2->setModel(r.AfficherTrierEt());

}

void Gestion_des_Rayons::on_commandLinkButton_2_clicked()
{

}
