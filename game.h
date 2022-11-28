#ifndef GAME_H
#define GAME_H


class game
{
public:
    game(int m,int l);
    int addMinecount(int x, int y, int& minecount);
    char getdata(int x, int y)const;
    char setdata(int x,int y);

private:
    char data[9][9];

    int a,b;

};

#endif // GAME_H
