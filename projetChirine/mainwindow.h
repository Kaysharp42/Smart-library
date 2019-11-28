#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "event.h"
#include "reclamation.h"
#include "contacts.h"
#include <QMainWindow>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_pb_supprimer_2_clicked();

private:
    Ui::MainWindow *ui;
     Event tmpevent;
     Reclamation tmprec;
     Contacts tmpcontact;
     QSystemTrayIcon * mSystemTrayIcon;
     QPropertyAnimation * animation;

};
#endif // MAINWINDOW_H
