#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QWidget>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
     ui->setupUi(this);

    Translator::get().set("en_US");



    QWidget* wid = new QWidget(this);

    setCentralWidget(wid);

    layout = new QVBoxLayout(wid);

    label1 = new QLabel;
    layout->addWidget(label1);
    label1->setText(tr("Hello"));
    label2 = new QLabel;
    layout->addWidget(label2);
    label2->setText(tr("name"));

    box = new QComboBox;

    box->addItem("English", "en_US");
    box->addItem("Armeenian", "hy_AM");
    layout->addWidget(box);

    connect(box, &QComboBox::currentIndexChanged, this, &MainWindow::handle);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::handle(int)
{
    QString lang = box->currentData().toString();
    Translator::get().set(lang);


    label1->setText(tr("Hello"));
    label2->setText(tr("name"));

    layout->addWidget(new Button);

}
