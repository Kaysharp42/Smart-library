#ifndef GESTION_DES_EMPLOYES_H
#define GESTION_DES_EMPLOYES_H
#include "etudiant.h"
#include "note.h"
#include <QMainWindow>

namespace Ui {
class Gestion_des_employes;
}
namespace Ui {
class MainWindow;
}
class Gestion_des_employes : public QMainWindow
{
    Q_OBJECT

public:
     Gestion_des_employes(QWidget *parent = nullptr);
    ~Gestion_des_employes();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_13_textEdited(const  QString &arg);

   // void on_comboBox_3_activated(const int &arg1);

   // void on_comboBox_3_currentIndexChanged(int index);

private:
    Ui::Gestion_des_employes *ui;
    Etudiant tmpetudiant;
    Note tmpnote;

};

#endif // GESTION_DES_EMPLOYES_H
