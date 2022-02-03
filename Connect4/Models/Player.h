//
//  Player.h
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#ifndef Player_h
#define Player_h

#include <vector>
using namespace std;

namespace Models {
class Player {
    int playerId;
public:
    Player(int pid)
    {
        playerId = pid;
    }
    int getId()
    {
        return playerId;
    }
    int getCol(vector<int> freeCols)
    {
        return freeCols[rand() % freeCols.size()];
    }
};
}

#endif /* Player_h */
