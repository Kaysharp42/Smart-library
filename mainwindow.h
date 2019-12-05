#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include "paiement.h"
#include <QMainWindow>
#include <QMessageBox>
#include "qcustomplot.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QtSql/QSqlDatabase>
#include "notification.h"
#include "connexion.h"

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

   /* void on_tabWidget_2_currentChanged(int index);*/

private:
    Ui::MainWindow *ui;
    commande tmpcmd;
    paiement tmppaiement;
    int etat=0;
    QString valeur;
};
#endif // MAINWINDOW_H
