#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "game.h"
#include "qpushbutton.h"
#include <QMouseEvent>

//class QPushButton;
//class RightB;

class Gui : public QWidget
{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr);
    void setui();
    void open();
    void clearz(int x,int y);
    void rightcl();

    void mousePressEvent(QMouseEvent *e);

signals:
    void rClicked();

private:
    QPushButton *tile[9][9];
    game *mine;
    int started=0;

    QPushButton *close;
};

/*class RightB : QPushButton
{
    Q_OBJECT

    public:
        explicit RightB(QWidget *parent = 0);

    private slots:
        void mousePressEvent(QMouseEvent *e);

    signals:
        void rClicked();

    public slots:

};

RightB::RightB(QWidget *parent) :
    QPushButton(parent)
{
}

void RightB::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rClicked();
}*/

#endif // GUI_H
