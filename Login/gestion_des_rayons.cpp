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
    ui->lineEdit_4->setValidator( new QIntValidator(0, 99999999, this) );
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

    QString id=ui->lineEdit_id_modif->text();
    int nbr=ui->lineEdit_4->text().toInt();
    int idd =ui->lineEdit_id_modif->text().toInt();
    ui->tableView_modifier->setModel(r.on_commandLinkButton_modifier_clicked(id));
    ui->tableView_modifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QString Categorie = ui->comboBox_new_Categ->currentText();
    Rayon r;
    bool test=r.modifier(idd,nbr,Categorie);
    QMessageBox msBox;

    if (test)
    {

        ui->tableView_modifier->setModel(r.on_commandLinkButton_modifier_clicked(id));
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
    QString id=ui->lineEdit_6->text();
    int  idd=ui->lineEdit_6->text().toInt();
    bool test=r.Supprimer(idd);
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


    ui->tableView_supp->setModel(r.on_commandLinkButton_modifier_clicked(id));
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
    QString id= ui->lineEdit_6->text();
    ui->tableView_supp->setModel(r.on_commandLinkButton_modifier_clicked(id));
    ui->tableView_supp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_pushButton_recher_modifier_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString id = ui->lineEdit_id_modif->text();
    ui->tableView_modifier->setModel(r.on_commandLinkButton_modifier_clicked(id));
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
    QString id =ui->lineEdit_etageSupp->text();
    ui->tableView_etageSupp->setModel(r.Afficher_ETA(id));
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_commandLinkButton_5_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    Rayon r;
    QString id = ui->lineEdit_etageSupp->text();
    QString e_id =ui->lineEdit_etageSupp->text();
    ui->tableView_etageSupp->setModel(r.Afficher_ETA(id));
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    ui->tableView_etageSupp->setModel(r.Afficher_ETA(id));
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void Gestion_des_Rayons::on_commandLinkButton_A_R_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();

    ui->stackedWidget->setCurrentIndex(1);


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
    QString Type =ui->comboBox_type_rec_pr->currentText() ;
    QMessageBox msBox;
    QString id =ui->lineEdit_rech_prod->text();
    if(Type =="Standard")
    {
        qDebug()<<Type;

        ui->tableView_produit->setModel(r.Afficher_produit(id));
        ui->tableView_produit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else if(Type =="Avancée")
    {
        qDebug()<<Type;
        ui->tableView_produit->setModel(r.Afficher_produit_Av(id));
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

void Gestion_des_Rayons::on_tableView_rayon_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_rayon->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from RAYON where ID='"+val+"' or NBR_ETAGERE='"+val+"' or CATEGORY='"+val+"'" );

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_Rayon_Id_Produit->setText(qry.value(0).toString());
        }
    }
}

void Gestion_des_Rayons::on_tableView_etage_2_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_etage_2->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from ETAGERE where ETAGERE_ID='"+val+"' or PRODUIT_ID='"+val+"' or QTT_PRODUIT='"+val+"' or ID='"+val+"' or NUM_ETAGE '"+val+"'" );

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_Etage_Id_Produit->setText(qry.value(0).toString());
            ui->lineEdit_Produit_Id_to_modifier->setText(qry.value(1).toString());
            ui->lineEdit_new_qtt->setText(qry.value(2).toString());
            ui->lineEdit_new_etage->setText(qry.value(4).toString());

        }
    }
}

void Gestion_des_Rayons::on_tableView_etage_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_etage->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from RAYON where ID='"+val+"' or NBR_ETAGERE='"+val+"' or CATEGORY='"+val+"'" );

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_rayonid->setText(qry.value(0).toString());
        }
    }
}
