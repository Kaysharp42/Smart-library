#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_sup_empl();
    void notification_Ouverture();
    void notification_sup_conge();
    void notification_sup_ss();
    void notification_sup_er();
    void notification_ajt_scc();
    void notification_ajt_er();
    void notification_DB_succ();
     void notification_DB_er();
    void  notification_sup_paiement();
    void notification_sup_cmd();
    void notification_Login_err();
    void notification_Login_scc();

};

#endif // NOTIFICATION_H
