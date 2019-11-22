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
    Event(int, QString,QString,QString);
    QString get_nom();
    QString get_type();
    QString get_lieu();
    int get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
public slots:
    void myfunction();
private:
    QString nom,type,lieu;
    int num;
};

#endif // EVENT_H
