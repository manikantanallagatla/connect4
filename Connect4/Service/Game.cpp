//
//  Game.cpp
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#include "Game.h"
#include <iostream>

using namespace std;

void Service::Game::playGame()
{
    while (1)
    {
        vector<int> colWiseFreeRow = b->getColWiseFreeRow();
        vector<int> freeCols;
        for (int i = 0; i < colWiseFreeRow.size(); i++)
        {
            if (colWiseFreeRow[i] >= 0)
            {
                freeCols.push_back(i);
            }
        }
        if (freeCols.size() == 0)
        {
            cout << "Game is a draw" << endl;
            break;
        }
        int col = players[turn]->getCol(freeCols);
        b->setPlayer(col, players[turn]);
        b->print();
        if (s->isWinningStep())
        {
            cout << "Player " << players[turn]->getId() << " WON" << endl;
            break;
        }
        turn++;
        turn %= players.size();
    }
}
