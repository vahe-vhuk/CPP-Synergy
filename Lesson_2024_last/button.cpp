#include "button.h"

Button::Button()
{
    this->setText(tr("Hello"));
    setStyleSheet("QPushButton {"
                       "background: black;"
                       "color: white;"
                       "border: 2px solid blue;"
                       "};"
                       "QPushButton::hover {"
                       "background: white;"
                       "color: black;"
                       "border: 1px solid black;"
                       "}");
}

void Button::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "left";
    } else if (event->button() == Qt::RightButton) {
        qDebug() << (event->button());
    } else {
        qDebug() << "other";
    }
}
