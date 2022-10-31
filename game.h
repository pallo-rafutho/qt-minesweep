#ifndef GAME_H
#define GAME_H


class game
{
public:
    game();
    int addMinecount(int x, int y, int& minecount);
    char getdata(int x, int y)const;

private:
    char data[9][9];

    int a,b;

};

#endif // GAME_H
