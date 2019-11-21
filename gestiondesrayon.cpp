#include "gestiondesrayon.h"
#include "ui_gestiondesrayon.h"
#include "ajouterrayon.h"
GestiondesRayon::GestiondesRayon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestiondesRayon)
{
    ui->setupUi(this);
}

GestiondesRayon::~GestiondesRayon()
{
    delete ui;
}

void GestiondesRayon::on_commandLinkButton_3_clicked()
{
ajouterRayon .show();
}
