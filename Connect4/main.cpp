#include <vector>
#include <iostream>

#include "Service/Game.h"
#include "Strategy/DefaultWinningStrategy.h"
#include "Models/Board.h"

using namespace std;
using namespace Service;

int main()
{
    Board *b = new Board(6, 6);
    WinningStrategy *st = new DefaultWinningStrategy(b);
    Game *g = new Game(b, st);
    g->playGame();
    return 0;
}
