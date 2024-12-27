#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QComboBox>
#include "translator.h"
#include "button.h"
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void handle(int);

  private:
    Ui::MainWindow *ui;

    QLabel* label1;
    QLabel* label2;
    QComboBox* box;
    QVBoxLayout* layout;
};
#endif // MAINWINDOW_H
