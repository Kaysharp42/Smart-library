#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class notification
{
private:
    int num;
public:
    notification();
    void notification_sup_cmd(QString);
    void notification_Ouverture(QString id);
    void notification_sup_paiement(QString id);
};

#endif // NOTIFICATION_H
