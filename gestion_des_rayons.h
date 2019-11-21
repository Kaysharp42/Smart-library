#ifndef GESTION_DES_RAYONS_H
#define GESTION_DES_RAYONS_H

#include <QDialog>
#include "rayon.h"
#include "etagere.h"
namespace Ui {
class Gestion_des_Rayons;
}

class Gestion_des_Rayons : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_des_Rayons(QWidget *parent = nullptr);
    ~Gestion_des_Rayons();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();


    void on_commandLinkButton_Ajouet_Rayon_clicked();

    void on_commandLinkButton_Annuler_ajout_clicked();

    void on_commandLinkButton_modifier_clicked();

    void on_commandLinkButton_annuler_modfi_clicked();

    void on_commandLinkButton_Supprimer_clicked();

    void on_commandLinkButton_annuler_supp_clicked();

    void on_pushButton_recherc_supp_clicked();

    void on_pushButton_recher_modifier_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_ajouter_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_annuler_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_6_clicked();

private:
    Ui::Gestion_des_Rayons *ui;
    Rayon r;
    Etagere E;

};

#endif // GESTION_DES_RAYONS_H
