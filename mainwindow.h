#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include "connexion.h"
#include "commande.h"
#include "livraison.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_ajouter_clicked();
    void on_afficher_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_ajouter_liv_clicked();
    void on_modifier_liv_clicked();
    void on_supprimer_liv_clicked();
    void on_afficher_liv_clicked();

private:
    Ui::MainWindow *ui;
    connexion Connexion;
};
#endif // MAINWINDOW_H
