#include "cnx.h"
#include "ui_cnx.h"
#include <QMessageBox>
#include "connexion.h"
#include "clients.h"

cnx::cnx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cnx)
{
    ui->setupUi(this);
}

cnx::~cnx()
{
    delete ui;
}

void cnx::on_pushButton_2_clicked()
{
    QString user = ui->lineEdit_id->text();
    QString mdp = ui->lineEdit_mdp->text();
    if (user == "test" && mdp == "test")
    {
        QMessageBox::information(this,"Login","ID et MDP correct");
        hide();
        Connexion c;
        bool test=c.createconnect();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Base de donnée ouverte"),
            QObject::tr("Connexion réussie"), QMessageBox::Ok);
            mainWindow=new MainWindow();
            mainWindow->show();

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Base de donnéen non ouverte"),
                        QObject::tr("Echec de connexion"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(this,"Login","ID et MDP non correct");
    }
}

void cnx::on_pushButton_clicked()
{
    Creer_Compte = new creer_compte();
    Creer_Compte->show();

}
