#include "setting.h"
#include "ui_setting.h"
#include <QFileDialog>
#include <QDir>
#include "ajouter_employe.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    // Настройка таблицы плейлиста
        m_playListModel = new QStandardItemModel(this);
        ui->playlistView->setModel(m_playListModel);
        // Устанавливаем заголовки таблицы
        m_playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")
                                                                << tr("File Path"));
        ui->playlistView->hideColumn(1);
        ui->playlistView->verticalHeader()->setVisible(false);
        ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->playlistView->horizontalHeader()->setStretchLastSection(true);

        m_player = new QMediaPlayer(this);
        m_playlist = new QMediaPlaylist(m_player);
        m_player->setPlaylist(m_playlist);
        m_player->setVolume(70);
        m_playlist->setPlaybackMode(QMediaPlaylist::Loop);


        connect(ui->btn_previous, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
        connect(ui->btn_next, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);
        connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
        connect(ui->btn_pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
        connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);

        connect(ui->playlistView, &QTableView::doubleClicked, [this](const QModelIndex &index){
            m_playlist->setCurrentIndex(index.row());
        });

        connect(m_playlist, &QMediaPlaylist::currentIndexChanged, [this](int index){
            ui->label->setText(m_playListModel->data(m_playListModel->index(index, 0)).toString());
        });
}

Setting::~Setting()
{
    delete ui;
    delete ui;
        delete m_playListModel;
        delete m_playlist;
        delete m_player;

}

void Setting::on_btn_add_clicked()
{
        QStringList files = QFileDialog::getOpenFileNames(this,
                                                          tr("Open files"),
                                                          QString(),
                                                          tr("Audio Files (*.mp3)"));
        foreach (QString filePath, files) {
            QList<QStandardItem *> items;
            items.append(new QStandardItem(QDir(filePath).dirName()));
            items.append(new QStandardItem(filePath));
            m_playListModel->appendRow(items);
            m_playlist->addMedia(QUrl(filePath));
        }
}

void Setting::on_pushButton_clicked()
{
         this->close();
}
