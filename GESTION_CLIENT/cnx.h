#ifndef CNX_H
#define CNX_H

#include <QDialog>
#include "clients.h"
#include "mainwindow.h"
#include "creer_compte.h"

namespace Ui {
class cnx;
}

class cnx : public QDialog
{
    Q_OBJECT

public:
    explicit cnx(QWidget *parent = 0);
    ~cnx();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::cnx *ui;
    MainWindow *mainWindow;
    creer_compte *Creer_Compte;
};

#endif // CNX_H
