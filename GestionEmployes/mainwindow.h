#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "etudiant.h"
#include "note.h"
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

    void on_pb_ajouter_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_lineEdit_13_textEdited( QString nom);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Etudiant tmpetudiant;
    Note tmpnote;
};

#endif // MAINWINDOW_H
