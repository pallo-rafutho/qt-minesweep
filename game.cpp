#include "game.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <QDebug>

game::game()
{
    srand(time(NULL));

    int con=0;

    for(int i=0;i<10;i++)
    {
        int x,y;
        while(true)
        {
            x = rand() % 9;
            y = rand() % 9;
            if(data[x][y] != '*')
            {
                data[x][y] = '*';
                con++;
                qDebug()<<con;
                break;
            }
        }
    }

    for(int y = 0; y < 9; y++)
    {
        for(int x = 0; x < 9; x++)
        {
            if(data[x][y] != '*')
            {
                int minecount = 0;
                addMinecount(x - 1, y - 1, minecount);
                addMinecount(x, y - 1, minecount);
                addMinecount(x + 1, y - 1, minecount);
                addMinecount(x - 1, y, minecount);
                addMinecount(x + 1, y, minecount);
                addMinecount(x - 1, y + 1, minecount);
                addMinecount(x, y + 1, minecount);
                addMinecount(x + 1, y + 1, minecount);

                char c =(char)(((int)'0')+minecount);
                data[x][y] = c;
            }
        }
    }

}

int game::addMinecount(int x, int y, int& minecount){
    if(x >= 0 && x < 9 && y >= 0 && y < 9)
    {
        if(data[x][y] == '*')
            minecount++;
    }
    return 0;
}

char game::getdata(int x,int y) const
{

    return data[x][y];

}
