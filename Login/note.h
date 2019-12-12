#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Note
{
public:
    Note();
    Note(int,int, QDateTime,QString, int);

    int get_id();
    int get_idn();

    int get_note();
    QString get_promotion();
    QDateTime get_datee();

    bool ajouter2();
    QSqlQueryModel * afficher();
    bool supprimer(int);

 private:
        QString promotion;

        QDateTime datee;

        int id,idn, note;
};

#endif // NOTE_H
