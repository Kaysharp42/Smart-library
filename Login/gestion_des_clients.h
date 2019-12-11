#ifndef GESTION_DES_CLIENTS_H
#define GESTION_DES_CLIENTS_H

#include <QMainWindow>
#include "clients.h"
#include "carte_fidelite.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_des_clients; }
QT_END_NAMESPACE



namespace Ui {
class MainWindow;
}

class Gestion_des_clients : public QMainWindow
{
    Q_OBJECT

public:
     Gestion_des_clients(QWidget *parent = nullptr);
    ~Gestion_des_clients();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_2_clicked();

    void on_Trier2_clicked();



    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

private:
    Ui::Gestion_des_clients *ui;
    Clients tmpetudiant;
    carte_fidelite tmpcartes_fidelite;
};

#endif // GESTION_DES_CLIENTS_H

