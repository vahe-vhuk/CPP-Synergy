#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class Button : public QPushButton {
    Q_OBJECT;
  public:
    Button();

  protected:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // BUTTON_H
