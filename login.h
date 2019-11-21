#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include "employe.h"
#include "gestion_des_rayons.h"
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

private:
Employe E;
Gestion_des_Rayons G;
};
#endif // LOGIN_H
