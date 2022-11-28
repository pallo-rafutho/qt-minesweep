#ifndef RIGHTB_H
#define RIGHTB_H

#include <QPushButton>

#include <QMouseEvent>

class RightB : public QPushButton
{
    Q_OBJECT

public:
        explicit RightB(QWidget *parent = 0);


private slots:
        void mousePressEvent(QMouseEvent *e);


signals:
        void rClicked();
        void lClicked();
        void dClicked();


};



#endif // RIGHTB_H
