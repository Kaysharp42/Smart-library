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
    Event(int, QString,QString,QDateTime,QString);
    QString get_nom();
    QString get_type();
    QString get_lieu();
    QDateTime get_date();
    int get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * trier ();
    QSqlQueryModel * rechercher(QString nom);
    bool modifier(Event);

public slots:
    void myfunction();
private:
    QString nom,type,lieu;
    int num;
    QDateTime datee;
};

#endif // EVENT_H
