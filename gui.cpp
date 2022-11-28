#include "gui.h"
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QColorDialog>
#include <QLabel>
#include <iostream>
#include <QString>




Gui::Gui(QWidget *parent)
    : QWidget{parent},
      count(new QLabel("10")),
      close(new QPushButton("close"))
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



            connect(tile[x][y],&RightB::lClicked,this,&Gui::open);
            connect(tile[x][y],&RightB::rClicked,this,&Gui::rightcl);
            connect(tile[x][y],&RightB::dClicked,this,&Gui::doublecl);
        }
    }


    connect(close,&QPushButton::clicked,this,&QWidget::close);


    setui();
    setMinimumSize(400,300);


}

void Gui::setui()
{
    QGridLayout *tic = new QGridLayout(this);
    tic->setSpacing(1);

    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            tic->addWidget(tile[x][y],x,y);
        }
    }

    tic->addWidget(count,1,10,2,2);
    tic->addWidget(close,3,10);





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
               if(a=="*")
               {
                   QColor col = Qt::red;
                   QString qss = QString("background-color: %1").arg(col.name());
                   tile[x][y]->setStyleSheet(qss);
               }
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
            if(k>=0 && k<9 && l>=0 && l<9 && tile[k][l]->text() !="f" && tile[k][l]->text() !="?")
            {


                        QString b;
                        b=mine->getdata(k,l);
                        tile[k][l]->setText(b);
                        QColor col = Qt::white;
                        QString qss = QString("background-color: %1").arg(col.name());
                        tile[k][l]->setStyleSheet(qss);
                        if(b=="*")
                        {
                            QColor col = Qt::red;
                            QString qss = QString("background-color: %1").arg(col.name());
                            tile[x][y]->setStyleSheet(qss);
                        }
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
                int n=count->text().toInt();
                n--;
                QString s= QString::number(n);
                count->setText(s);
            }
            else if(tile[x][y]==qobject_cast<RightB *>(this->sender()) && tile[x][y]->text()=="f")
            {
                tile[x][y]->setText("?");
                int n=count->text().toInt();
                n++;
                QString s= QString::number(n);
                count->setText(s);
            }
            else if(tile[x][y]==qobject_cast<RightB *>(this->sender()) && tile[x][y]->text()=="?")
            {
                tile[x][y]->setText("");
            }
        }
    }

}

void Gui::doublecl()
{
    int flag=0;
    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
        {
            if(tile[x][y]==qobject_cast<RightB *>(this->sender()))
            {
                for(int k=x-1;k<=x+1;k++)
                {
                    for(int l=y-1;l<=y+1;l++)
                    {
                        if(tile[k][l]->text()=="f")
                            flag++;

                    }
                }
                if(tile[x][y]->text().toInt()==flag)
                    clearz(x,y);
            }
        }
    }

}
