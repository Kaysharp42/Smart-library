#include "tri.h"
#include "ui_tri.h"
#include "etudiant.h"

tri::tri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tri)
{
    Etudiant e ;
    ui->setupUi(this);
    ui->tableView->setModel(e.trier());
}

tri::~tri()
{
    delete ui;

}

