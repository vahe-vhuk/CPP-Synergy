#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , vol{new Volume(this)}
{
    this->resize(500, 500);

    vol->resize(300, 300);

}

MainWindow::~MainWindow() {}
