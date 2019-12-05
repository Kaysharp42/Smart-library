#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "event.h"
#include "reclamations.h"
#include "contacts.h"
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

    void on_pushButton_21_clicked();

    void on_pushButton_23_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_supprimer_2_clicked();

private:
    Ui::MainWindow *ui;
    Event tmpevent;
    Reclamations tmprec;
    Contacts tmpcontact;

};

#endif // MAINWINDOW_H
