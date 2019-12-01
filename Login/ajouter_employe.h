#ifndef AJOUTER_EMPLOYE_H
#define AJOUTER_EMPLOYE_H

#include <QDialog>
#include "employe.h"
namespace Ui {
class Ajouter_Employe;
}

class Ajouter_Employe : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_Employe(QWidget *parent = nullptr);
    ~Ajouter_Employe();
Ui::Ajouter_Employe *ui;
 QSqlQueryModel * AfficherS();
private slots:
    void on_commandLinkButton_clicked();

    void on_pb_supp_clicked();

    void on_search_bf_delete_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_disconnect_clicked();


    void on_pushButton_Trier_clicked();

    void on_table_empl_clicked(const QModelIndex &index);

private:

    Employe E;
};

#endif // AJOUTER_EMPLOYE_H
