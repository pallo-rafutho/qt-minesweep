#include "rightb.h"
#include <QMouseEvent>

RightB::RightB(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, &QPushButton::clicked,[&]{});
}

void RightB::mousePressEvent(QMouseEvent *e)
{

    if(e->button()==Qt::RightButton)
        emit rClicked();

    if(e->button()==Qt::LeftButton)
        emit lClicked();
}

