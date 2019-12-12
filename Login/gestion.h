#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include "paiement.h"
#include "livraison.h"
#include <QMainWindow>
#include <QMessageBox>
#include "qcustomplot.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QtSql/QSqlDatabase>
#include "notification.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();
private slots:
    void sendMail();
    void mailSent(QString);

private slots:
    void on_ajouter_clicked();



    void on_supprimer_clicked();

    void on_modifier_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_5_activated(const QString &arg1);

    void on_lineEdit_19_textChanged(const QString &arg1);

    void on_checkBox_2_stateChanged(int arg1);


    void on_ajouter_2_clicked();

    void on_supprimer_2_clicked();

    void on_comboBox_6_activated(const QString &arg1);


    void on_modifier_3_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_lineEdit_20_textChanged(const QString &arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_ajouter_liv_clicked();
    void on_modifier_liv_clicked();
    void on_supprimer_liv_clicked();
    void on_lineEdit_21_textChanged(const QString &arg1);
    void on_comboBox_7_activated(const QString &arg1);
    void on_checkBox_4_stateChanged(int arg1);
    void on_comboBox_8_activated(const QString &arg1);

   /* void on_tabWidget_2_currentChanged(int index);*/

    void on_pushButton_clicked();

    void on_refreshaff_clicked();

    void on_view_clicked();

    void on_refresh2_clicked();

    void on_refreshliv_clicked();


    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    commande tmpcmd;
    paiement tmppaiement;
    livraison tmpliv;
    int etat=0;
    QString valeur;
    Notification N;
};
#endif // MAINWINDOW_H
