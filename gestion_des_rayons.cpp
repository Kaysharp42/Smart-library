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

Gestion_des_Rayons::Gestion_des_Rayons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_des_Rayons)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_idrayon->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tableView_ajouter->setModel(r.Afficher());
    ui->tableView_etage->setModel(E.Afficher());


}

Gestion_des_Rayons::~Gestion_des_Rayons()
{
    delete ui;
}

void Gestion_des_Rayons::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Gestion_des_Rayons::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void Gestion_des_Rayons::on_commandLinkButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}
void Gestion_des_Rayons::on_commandLinkButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}


void Gestion_des_Rayons::on_commandLinkButton_Ajouet_Rayon_clicked()
{
   ui->tableView_ajouter->setModel(r.Afficher());
      ui->tableView_ajouter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int id=ui->lineEdit_idrayon->text().toInt();
    int nbr=ui->lineEdit_nbr->text().toInt();

    Rayon R(id,nbr);
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
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_commandLinkButton_modifier_clicked()
{
    ui->tableView_modifier->setModel(r.Afficher());
       ui->tableView_modifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
int id=ui->lineEdit_id_modif->text().toInt();
int nbr=ui->lineEdit_4->text().toInt();
Rayon r;
bool test=r.modifier(id,nbr);
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
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_commandLinkButton_Supprimer_clicked()
{
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
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_pushButton_recherc_supp_clicked()
{
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
    this->close();
    //LogIn().show();
}

void Gestion_des_Rayons::on_commandLinkButton_ajouter_clicked()
{
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

        ui->stackedWidget->setCurrentIndex(0);



}

void Gestion_des_Rayons::on_pushButton_2_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
          model->setQuery("SELECT * FROM ETAGERE WHERE ETAGERE_ID ='"+ui->lineEdit_etageSupp->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ETAGERE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRODUIT_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTT_PRODUIT"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_commandLinkButton_5_clicked()
{
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
    ui->tableView_etageSupp->setModel(model);
    ui->tableView_etageSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Gestion_des_Rayons::on_commandLinkButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void Gestion_des_Rayons::on_commandLinkButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}
