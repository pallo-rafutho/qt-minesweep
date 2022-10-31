#include "gui.h"
#include <QPushButton>
#include <QGridLayout>


Gui::Gui(QWidget *parent)
    : QWidget{parent},      

      close(new QPushButton("close"))
{

    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            //QString a="";
            //a+=mine->getdata(x,y);

            tile[x][y] =new RightB("");
            tile[x][y]->setFixedSize(30,30);
            connect(tile[x][y],&QPushButton::clicked,this,&Gui::open);

            QPalette pall = tile[x][y]->palette();
            pall.setColor(QPalette::Button, QColor(Qt::blue));
            tile[x][y]->setAutoFillBackground(true);
            tile[x][y]->setPalette(pall);
            tile[x][y]->update();

        }
    }

    //connect(tile[x()][y()],&QPushButton::clicked,this,&Gui::open);
    setui();
    setMinimumSize(300,300);


}

void Gui::setui()
{
    QGridLayout *tic = new QGridLayout(this);
    tic->setSpacing(0);

    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            tic->addWidget(tile[x][y],x,y);
        }
    }


    //tic->addWidget();
}

void Gui::open()
{
    if(started==0)
    {
        mine= new game;
        started=1;
    }
    //mine= new game;
    QString a;

   for(int x=0;x<9;x++)
   {
       for(int y=0;y<9;y++)
       {
           if(tile[x][y]==qobject_cast<QPushButton *>(this->sender()))
           {
               a=mine->getdata(x,y);
               tile[x][y]->setText(a);
               if(tile[x][y]->text()=="0")
               {
                   clearz(x-1,y-1);
               }
           }

       }
   }

   //if(tile[x][y]->text()=="0")

}

void Gui::clearz(int x, int y)
{
    if(x>=0 && x<9 && y>=0 && y<9 && tile[x][y]->text() !="f")
    {
        QString b;
        b=mine->getdata(x,y);
        tile[x][y]->setText(b);
    }
}
