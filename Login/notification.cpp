#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}
void Notification::notification_sup_empl()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un employer a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}

void Notification::notification_sup_conge()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un conge a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}


void Notification::notification_Ouverture()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'employer ","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
void Notification::notification_ajt_scc()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("New Notification ","Ajouté avec succès",QSystemTrayIcon::Information,15000);
//num++;
}void Notification::notification_ajt_er()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("New Notification ","Échec de l'ajout",QSystemTrayIcon::Information,15000);
//num++;
}void Notification::notification_sup_ss()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("New Notification ","Supprimé avec succès",QSystemTrayIcon::Information,15000);
//num++;
}
void Notification::notification_sup_er()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("New Notification ","Échec de la suppression",QSystemTrayIcon::Information,15000);
//num++;
}
void Notification::notification_DB_succ()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("database is open ","connection successful.",QSystemTrayIcon::Information,15000);
//num++;
}
void Notification::notification_DB_er()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("database is not open ","connection failed.",QSystemTrayIcon::Information,15000);
//num++;
}
