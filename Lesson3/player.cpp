#include "player.h"

Player::Player(QWidget* parrent)
    : QWidget{parrent}
{
    setFixedSize(400, 200);

    init();
    setup();
    setup_conections();
    chlp();
}

void Player::handle_play()
{
    if (player->isPlaying()) {
        player->pause();
        start->setText("▶");
    }
    else {
        player->play();
        start->setText("⏸");
    }
}

void Player::handle_next()
{

}

void Player::handle_prev()
{

}

void Player::handle_mute()
{
    if(out->isMuted()) {
        out->setMuted(false);
    }
    else {
        out->setMuted(true);
    }
}

void Player::handle_volume_slider(int new_value)
{
    out->setVolume(float(new_value)/100);
}

void Player::handle_audio_slider(int new_value)
{
    if (!flag) {
        flag = true;
        player->setPosition(qint64(new_value) * 1000);
        flag = false;
    }

    qint64 seconds = new_value;

    int min = seconds / 60;
    seconds %= 60;
    duration->setText(QString::number(min) + ":" + QString::number(seconds));
}

void Player::handle_audio_position(qint64 new_pos)
{
    if (!flag) {
        flag  = true;
        audio_slider->setValue(new_pos / 1000);
        flag = false;
    }
    // qDebug() << new_pos;

    // qint64 seconds = new_pos / 1000;

    // int min = seconds / 60;
    // seconds %= 60;
    // duration->setText(QString::number(min) + ":" + QString::number(seconds));
}

void Player::handle_meta_data()
{
    audio_slider->setMinimum(0);

    audio_slider->setMaximum(player->duration() / 1000);

    // QMediaMetaData mddata = player->metaData();
    // music_name->setText(mddata[QMediaMetaData::Title].toString());

}

void Player::init()
{
    flag = false;


    start = new QPushButton("▶", this);
    next = new QPushButton("⏭", this);
    prev = new QPushButton("⏮", this);

    volume_slider = new QSlider(this);
    audio_slider = new QSlider(this);

    music_name = new QLabel("__..__", this);
    duration = new QLabel("00:00", this);

    mute = new QPushButton("🔊", this);

    player = new QMediaPlayer(this);
    out = new QAudioOutput(this);


    player->setAudioOutput(out);

    player->setSource(QUrl("https://musicd.okcdn.ru/v0/stream?id=v0_10119087067_1_1&cid=v0_10119087067_1_1&fid=123305678935057&uid=dbd53df06298f06d9554075cd2c39e13&sid=0e46d9e8cb8539df655c0f1fbd59b22d8841d0e8cf84d792789905fccc149ea79fbb9785cc975d334f428be77271e900c97b265f4a520ba69f30c09244d079e4&ts=1734264618523&md5=27a26f7b82b1fdc52181ade05b343bf6&client=web&clientHash=116774577321123523547953161205112154532523523515161187455511591851751872232212071333"));
    //player->setSource(QUrl(""));


}

void Player::setup()
{
    music_name->setGeometry(10, 10, 380, 30);
    music_name->setAlignment(Qt::AlignCenter);

    volume_slider->setGeometry(310, 160, 80, 40);
    volume_slider->setOrientation(Qt::Horizontal);


    mute->setGeometry(280, 165, 20, 30);

    start->setGeometry(125, 165, 30, 30);
    prev->setGeometry(85, 165, 30, 30);
    next->setGeometry(165, 165, 30, 30);

    audio_slider->setOrientation(Qt::Horizontal);
    audio_slider->setGeometry(10, 135, 330, 25);


    duration->setGeometry(350, 135, 40, 20);
}

void Player::setup_conections()
{
    connect(start,SIGNAL(clicked()), this, SLOT(handle_play()));

    connect(next, SIGNAL(clicked(bool)), this, SLOT(handle_next()));
    connect(prev, SIGNAL(clicked(bool)), this, SLOT(handle_prev()));

    connect(mute, SIGNAL(clicked(bool)), this, SLOT(handle_mute()));
    connect(volume_slider, SIGNAL(valueChanged(int)), this, SLOT(handle_volume_slider(int)));


    connect(player, SIGNAL(metaDataChanged()), this, SLOT(handle_meta_data()));


    connect(audio_slider, SIGNAL(valueChanged(int)), this, SLOT(handle_audio_slider(int))) ;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(handle_audio_position(qint64)));

}

void Player::chlp()
{
    volume_slider->setMinimum(0);
    volume_slider->setMaximum(100);
    volume_slider->setValue(20);
}
