#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QSlider>
#include <QMediaMetaData>


class Player : public QWidget {
    Q_OBJECT
  public:
    Player(QWidget* parrent = nullptr);


  private slots:
    void handle_play();
    void handle_next();
    void handle_prev();
    void handle_mute();

    void handle_volume_slider(int new_value);
    void handle_audio_slider(int new_value);

    void handle_audio_position(qint64 new_pos);

    void handle_meta_data();


  private:
    QPushButton* start;
    QPushButton* next;
    QPushButton* prev;

    QSlider* volume_slider;
    QSlider* audio_slider;

    QLabel* music_name;
    QLabel* duration;

    QPushButton* mute;

    QMediaPlayer* player;
    QAudioOutput* out;

    bool flag;

  private:
    void init();
    void setup();
    void setup_conections();
    void chlp();

};

#endif // PLAYER_H
