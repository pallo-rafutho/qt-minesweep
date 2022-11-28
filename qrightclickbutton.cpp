#include "qrightclickbutton.h"

QRightClickButton::QRightClickButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, &QPushButton::clicked,[&]{});
}

void QRightClickButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();
}
