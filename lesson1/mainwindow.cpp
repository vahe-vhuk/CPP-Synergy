#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , label(new QLabel("0", this))
    , btn(new QPushButton("Click me!!", this))
{


    this->setFixedSize(300, 200);

    label->setGeometry(100, 30, 100, 40);
    label->setStyleSheet("background: red;");
    label->setAlignment(Qt::AlignCenter);

    btn->setGeometry(100, 130, 100, 40);


    connect(btn, SIGNAL(clicked()), this, SLOT(increment()));


}

MainWindow::~MainWindow() {  }

void MainWindow::increment()
{
    qint32 val = label->text().toInt();
    ++val;
    label->setText(QString::number(val));
}
