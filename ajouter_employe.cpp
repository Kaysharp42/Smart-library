#include "ajouter_employe.h"
#include "ui_ajouter_employe.h"
#include "employe.h"
#include "login.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
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
  //  QSqlQueryModel * model = new QSqlQueryModel();
  //  ui->table_empl->setModel(model);
   // ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   // model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("NUM_CIN"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPARTEMENT"));


   // ui->table_empl->setModel(model);
  //  ui->table_empl->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QString Login_Id = ui->lineEdit_loginid->text();  //text().toInt()
    QString Login_Pass = ui->lineEdit_loginpass->text();
    QString Empl_Id = ui->lineEdit_Emp_id->text();


   Employe e(Empl_Id,Login_Id,Login_Pass);
   bool test=e.Ajouter_Employe();
   QMessageBox msBox;
   if (test)
   {
      // ui->Tab_Etudiant->setModel(attmp.Afficher());

       msBox.setText("Ajouter avec succées");
                     msBox.exec();
   } else
   {
       msBox.setText("ERROR");
                     msBox.exec();
   }
}

void Ajouter_Employe::on_pb_supp_clicked()
{

    Employe e;
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
    QString id;
    QSqlQuery query;
    id= ui->lineEdit_Supp->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableSupp->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
          model->setQuery("SELECT * FROM COMPTE WHERE LOGIN_ID ='"+ui->lineEdit_Supp->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));
    ui->tableSupp->setModel(model);
    ui->tableSupp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}


void Ajouter_Employe::on_pushButton_clicked()
{
    QString id;
    QSqlQuery query;
    QSqlQueryModel * model = new QSqlQueryModel();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    id=ui->lineEdit_4->text();
          model->setQuery("SELECT * FROM COMPTE WHERE LOGIN_ID ='"+ui->lineEdit_4->text()+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMPLOYE_ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("LOGIN_ID"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("LOGIN_PASSWORD"));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Ajouter_Employe::on_commandLinkButton_2_clicked()
{
   LogIn().show();
   this->close();
}

void Ajouter_Employe::on_commandLinkButton_disconnect_clicked()
{
    LogIn().show();
    this->close();
}
