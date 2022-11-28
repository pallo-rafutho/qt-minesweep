#include "game.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <QDebug>

game::game(int m, int l)
{
    srand(time(NULL));



    data[m][l]='0';

    for(int i=0;i<10;i++)
    {

        int x,y;
        int che=0;
        int send=0;
        while(send==0)
        {
            x = rand() % 9;
            y = rand() % 9;
            if(data[x][y] != '*' &&  data[x][y] != '0'  )
            {
                for(int k=x-1; k<=x+1; k++)
                    for(int l=y-1; l<=y+1; l++)
                    {
                        if(data[k][l] == '0')
                            che=1;

                    }
                if(che != 1)
                {
                data[x][y] = '*';
                send=1;

                }

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


