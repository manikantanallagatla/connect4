//
//  Game.h
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#ifndef Game_h
#define Game_h

#include <vector>
#include "../Models/Board.h"
#include "../Models/Player.h"
#include "../Models/Cell.h"
#include "../Strategy/WinningStrategy.h"

using namespace Models;
using namespace std;
using namespace Strategy;

namespace Service {
class Game {
    Board *b;
    vector<Player*> players;
    WinningStrategy *s;
    int turn;
public:
    Game(Board *board, WinningStrategy* st)
    {
        srand(time(NULL));
        
        b = board;
        players.push_back(new Player(1));
        players.push_back(new Player(2));
        turn = 0;
        s = st;
    }
    
    void playGame();
};
}

#endif /* Game_h */
