#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400, 200);
    player = new Player(this);
    // player->show();
}

MainWindow::~MainWindow() {}
