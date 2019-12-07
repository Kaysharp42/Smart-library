#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clients.h"
#include "carte_fidelite.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
    Clients tmpetudiant;
    carte_fidelite tmpcartes_fidelite;
};

#endif // MAINWINDOW_H
