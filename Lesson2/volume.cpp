#include "volume.h"

Volume::Volume(QWidget* parent)
    : QWidget(parent)
    , label{new QLabel(this)}
    , slider{new QSlider(this)}
{
    this->setStyleSheet("background: blue");
    slider->setOrientation(Qt::Horizontal);
    slider->setGeometry(30, 30, 100, 30);

    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setSingleStep(2);


    label->setGeometry(30, 80, 30, 30);
    label->setText("0");

    connect(slider, &QSlider::valueChanged, this, &Volume::handle_value_change);
}

void Volume::handle_value_change(int new_value)
{
    label->setText(QString::number(float(new_value)/10));
}
