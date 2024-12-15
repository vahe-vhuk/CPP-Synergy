#ifndef VOLUME_H
#define VOLUME_H

#include <QSlider>
#include <QLabel>


class Volume : public QWidget {
    Q_OBJECT
  public:
    Volume(QWidget* parent = nullptr);


  private:
    QLabel* label;
    QSlider* slider;

  private slots:
    void handle_value_change(int new_value);

};

#endif // VOLUME_H
