#include "gui.h"
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QColorDialog>



Gui::Gui(QWidget *parent)
    : QWidget{parent}
{


    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            //QString a="";
            //a+=mine->getdata(x,y);


            tile[x][y] =new RightB(this);


            tile[x][y]->setFixedSize(30,30);

            QColor col = Qt::blue;
            QString qss = QString("background-color: %1").arg(col.name());
            tile[x][y]->setStyleSheet(qss);

//            QPalette pall = tile[x][y]->palette();
//            pall.setColor(QPalette::Button, QColor(Qt::blue));
//            tile[x][y]->setAutoFillBackground(true);
//            tile[x][y]->setPalette(pall);
//            tile[x][y]->update();

            connect(tile[x][y],&RightB::lClicked,this,&Gui::open);
            connect(tile[x][y],&RightB::rClicked,this,&Gui::rightcl);
        }
    }





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
        for(int x=0;x<9; x++){

            for(int y=0;y<9;y++)
            {
                if(tile[x][y]==qobject_cast<RightB *>(this->sender()))
                 mine= new game(x,y);

            }
        }
        started=1;
    }

    QString a;


   if(qobject_cast<RightB *>(this->sender())->text()!="f")
   for(int x=0;x<9;x++)
   {
       for(int y=0;y<9;y++)
       {
           if(tile[x][y]==qobject_cast<RightB *>(this->sender()))
           {
               a=mine->getdata(x,y);
               tile[x][y]->setText(a);
               QColor col = Qt::white;
               QString qss = QString("background-color: %1").arg(col.name());
               tile[x][y]->setStyleSheet(qss);
               if(tile[x][y]->text()=="0")
               {

                    clearz(x,y);

               }

           }

       }
   }

   //if(tile[x][y]->text()=="0")

}

void Gui::clearz(int x, int y)
{

    for(int k=x-1;k<=x+1;k++)
        for(int l=y-1;l<=y+1;l++)
        {
            if(k>=0 && k<9 && l>=0 && l<9 && tile[k][l]->text() !="f")
            {


                        QString b;
                        b=mine->getdata(k,l);
                        tile[k][l]->setText(b);
                        QColor col = Qt::white;
                        QString qss = QString("background-color: %1").arg(col.name());
                        tile[k][l]->setStyleSheet(qss);
                        cleard.append(tile[x][y]);


                        if(tile[k][l]->text()=="0" && !cleard.contains(tile[k][l]))
                        {

                            clearz(k,l);
                        }


            }
        }
}

void Gui::rightcl()
{
    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            if(tile[x][y]==qobject_cast<RightB *>(this->sender()) && tile[x][y]->text()=="")
            {
                tile[x][y]->setText("f");
            }
            else if(tile[x][y]==qobject_cast<RightB *>(this->sender()) && tile[x][y]->text()=="f")
            {
                tile[x][y]->setText("?");
            }
            else if(tile[x][y]==qobject_cast<RightB *>(this->sender()) && tile[x][y]->text()=="?")
            {
                tile[x][y]->setText("");
            }
        }
    }

}
