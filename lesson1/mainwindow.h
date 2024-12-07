#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QPushButton>
#include <QString>


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

  private:

    QLabel* label;
    QPushButton* btn;

  private slots:

    void increment();

};
#endif // MAINWINDOW_H




