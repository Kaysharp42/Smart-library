#ifndef GESTION_DES_RAYONS_H
#define GESTION_DES_RAYONS_H

#include <QDialog>
#include "rayon.h"
#include "etagere.h"
#include <QTimer>

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

    void on_commandLinkButton_annuler_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_A_R_clicked();

    void on_commandLinkButton_M_R_clicked();

    void on_commandLinkButton_S_R_clicked();

    void on_commandLinkButton_A_E_clicked();

    void on_commandLinkButton_S_E_clicked();

    void on_commandLinkButton_AF_F_clicked();

    void on_pushButton_Add_new_Product_clicked();

    void on_pushButton_Mod_Product_Qtt_clicked();

    void on_pushButton_Mod_Product_num_etage_clicked();

    void UpdateTime();

    void on_commandLinkButton_rech_produit_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_order_clicked();

    void on_pushButton_trier_clicked();

    void on_commandLinkButton_2_clicked();

    void on_tableView_rayon_clicked(const QModelIndex &index);

    void on_tableView_etage_2_clicked(const QModelIndex &index);

    void on_tableView_etage_clicked(const QModelIndex &index);

private:
    Ui::Gestion_des_Rayons *ui;
    Rayon r;
    QTimer *timer_1s;
    Etagere E;

};

#endif // GESTION_DES_RAYONS_H
