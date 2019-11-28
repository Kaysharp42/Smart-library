#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTimer>
#include <QDateTime>

class Event
{
public:
    Event();
    Event(int, QString,QString,int,QString);
    QString get_nom();
    QString get_type();
    QString get_lieu();
    int get_num();
    int get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * trier ();
    QSqlQueryModel * rechercher(QString nom);

public slots:
    void myfunction();
private:
    QString nom,type,lieu;
    int num, datee;
};

#endif // EVENT_H
