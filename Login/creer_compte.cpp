#include "creer_compte.h"
#include <QMessageBox>
#include "ui_creer_compte.h"

creer_compte::creer_compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creer_compte)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/doctor-gp-netherlands.jpg");
    ui->picture->setPixmap(pix);
}

creer_compte::~creer_compte()
{
    delete ui;
}

void creer_compte::on_pushButton_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->prenom->text();
    QString id = ui->identifiant->text();
    QString mdp = ui->motdepasse->text();
    QString idmedical = ui->IDmedical->text();
    if (nom == "" || prenom == "" || id == "" || mdp == "" || idmedical == "" )
    {
        QMessageBox::information(this,"Login","Touts les champs sont obligatoires");
    }
    if (!(ui->radioButton->isChecked() || ui->radioButton_2->isChecked()))
    {
        QMessageBox::information(this,"Information","Selectionnez au moins un titre");
    }
}

void creer_compte::on_pushButton_2_clicked()
{
    close();
}


