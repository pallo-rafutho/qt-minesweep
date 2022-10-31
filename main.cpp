#include <QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Gui g;

    g.show();


    return a.exec();
}

// the purpose of this app is to have a number of mini games such as, tic tak toe , tetris and connect four
