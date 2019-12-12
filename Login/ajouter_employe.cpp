#include "ajouter_employe.h"
#include "ui_ajouter_employe.h"
#include "employe.h"
#include "login.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
#include <QSound>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>


Ajouter_Employe::Ajouter_Employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_Employe)
{
    ui->setupUi(this);
    //  ui->lineEdit_CIN->setValidator( new QIntValidator(0, 99999999, this) );
    ui->table_empl->setModel(E.AfficherC());
}

Ajouter_Employe::~Ajouter_Employe()
{
    delete ui;
}


void Ajouter_Employe::on_commandLinkButton_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();

    QString Login_Id = ui->lineEdit_loginid->text();  //text().toInt()
    QString Login_Pass = ui->lineEdit_loginpass->text();
    QString Empl_Id = ui->lineEdit_Emp_id->text();
    Employe e(Empl_Id,Login_Id,Login_Pass);
    bool test=e.Ajouter_Employe();
    if (test)
    {
N.notification_ajt_scc();
    } else
    {
N.notification_ajt_er();
    }
}

void Ajouter_Employe::on_pb_supp_clicked()
{
    //  ui->pb_supp->setStyleSheet("border-image: url(:/new/prefix1/MyResources/deleteClicked.png)3 10 15 10;font: 24pt Bahnschrift;");
    Employe e;
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString id=ui->lineEdit_Supp->text();
    bool test=e.Supprimer(id);
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
}

void Ajouter_Employe::on_search_bf_delete_clicked()
{

    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    QString id;
    QSqlQuery query;
    id= ui->lineEdit_Supp->text();
    ui->tableSupp->setModel(E.Afficher_on_search_bf_delete_clicked(id));
    ui->tableSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}


void Ajouter_Employe::on_pushButton_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();

    QString id;
    QSqlQuery query;
    id=ui->lineEdit_4->text();
    QString Type = ui->comboBox_Type_Rc->currentText();
    if (ui->radioButton_c->isChecked())
    {
        if (Type =="Standard")
        {
            ui->tableView->setModel(E.Afficher_on_search_bf_delete_clicked(id));
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        } else if (Type == "avancée")
        {
            ui->tableView->setModel(E.Afficher_on_pushButton_clicked(id));
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            QMessageBox msBox;
            msBox.setText("Please select type");
            msBox.exec();
        }
    } else if (ui->radioButton_d->isChecked())
    {
        if (Type =="Standard")
        {
            ui->tableView->setModel(E.Afficher_on_pushButton_clicked_DESC(id));
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        } else if (Type == "avancée")
        {

            ui->tableView->setModel(E.Afficher_on_pushButton_clicked_AV_DESC(id));
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            QMessageBox msBox;
            msBox.setText("Please select type");
            msBox.exec();
        }
    }
}

void Ajouter_Employe::on_commandLinkButton_2_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();
    this->close();
}

void Ajouter_Employe::on_commandLinkButton_disconnect_clicked()
{
    QSound Clicked(":/new/prefix1/MyResources/Click.wav");
    Clicked.play();

    this->close();
}


void Ajouter_Employe::on_pushButton_Trier_clicked()
{

    ui->table_empl->setModel(E.AfficherC_Ordered());
    ui->table_empl->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Ajouter_Employe::on_table_empl_clicked(const QModelIndex &index)
{
    QString val=ui->table_empl->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from EMPLOYES where EMPLOYES_ID='"+val+"' or DEPARTEMENT='"+val+"'" );

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_Emp_id->setText(qry.value(0).toString());
        }
    }
}

void Ajouter_Employe::on_Settings_clicked()
{
   // this->hide();
    S.show();
}
