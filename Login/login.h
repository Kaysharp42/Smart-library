#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QtWidgets/QMessageBox>
#include "employe.h"
#include "gestion_des_rayons.h"
#include "setting.h"
#include "notification.h"
#include "gestion_des_clients.h"
#include "gestion.h"
#include "gestion_rh.h"
QT_BEGIN_NAMESPACE
namespace Ui { class LogIn; }
QT_END_NAMESPACE

class LogIn : public QMainWindow
{
    Q_OBJECT

public:
    LogIn(QWidget *parent = nullptr);
    ~LogIn();
      Ui::LogIn *ui;

private slots:

    void on_LoginB_clicked();

    void on_actionCheck_Data_Base_triggered();

    void on_actionSettings_triggered();


private:
Employe E;
Gestion_des_Rayons G;
Setting s;
Notification N;
Gestion_des_clients GC;
MainWindow C;
Gestion_RH M;
};
#endif // LOGIN_H
