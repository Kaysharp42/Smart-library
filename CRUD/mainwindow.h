#define MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "commandef.h"
#include <QMainWindow>
#include <connexion.h>


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
    void on_ajouter_2_clicked();


    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
void on_pushButton_8_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();


    void on_affichsup_clicked();

    void on_afficher2_clicked();

    void on_modifierc_clicked();

    void on_refreshc_clicked();

    void on_affcmd_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur tmpfournisseur;
    commandef tmpcommandef;
};
