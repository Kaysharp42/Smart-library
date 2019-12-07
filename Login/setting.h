#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private slots:
    void on_btn_add_clicked();

    void on_pushButton_clicked();

private:
    Ui::Setting *ui;
    QStandardItemModel * m_playListModel ;  // Playlist data model to display
        QMediaPlayer * m_player ;  // Track player
        QMediaPlaylist * m_playlist ;  // Player playlist
};

#endif // SETTING_H
