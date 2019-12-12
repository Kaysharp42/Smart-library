#ifndef GESTION_RH_H
#define GESTION_RH_H

#include <QMainWindow>
#include "event.h"
#include "reclamations.h"
#include "contacts.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QDebug>
#include "ui_gestion_rh.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_RH; }
QT_END_NAMESPACE
class QSystemTrayIcon;

class Gestion_RH : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_RH(QWidget *parent = nullptr);
    ~Gestion_RH();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_pb_supprimer_2_clicked();

    void on_SliderProgress_sliderMoved(int position);

    void on_sliderVolume_actionTriggered(int action);

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_position_Changed(int position);

    void on_duration_Changed(int position);

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_sendBtn_clicked();


   // void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_ModifierEvent_clicked();

    void on_ajouter_event_clicked();

    void on_quit_ajouter_event_clicked();

    void on_pushButton_22_clicked();

    void on_ajouter_event_2_clicked();

    void on_supprimer_event_clicked();

    void on_supprimer_contact_clicked();

    void on_ajouter_rec_clicked();

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_pushButton_14_clicked();

    void on_supprimer_event_2_clicked();



private:
    Ui::Gestion_RH *ui;
    Event tmpevent;
    Reclamations tmprec;
    Contacts tmpcontact;
    QSystemTrayIcon * mSystemTrayIcon;
    QPropertyAnimation * animation;
    QMediaPlayer* player;


};
#endif // GESTION_RH_H
