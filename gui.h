#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "game.h"

#include "rightb.h"
#include <QList>
class QLabel;



class Gui : public QWidget
{
    Q_OBJECT
public:
    explicit Gui(QWidget *parent = nullptr);
    void setui();

    void clearz(int x,int y);
    void rightcl();
    void doublecl();
    void open();

private:
    RightB *tile[9][9];
    game *mine;
    int started=0;
    QList<RightB *> cleard;
    QLabel *count;
    QPushButton *close;



};




#endif // GUI_H
