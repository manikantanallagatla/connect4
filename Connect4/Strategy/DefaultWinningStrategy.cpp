//
//  DefaultWinningStrategy.cpp
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#include "DefaultWinningStrategy.h"

bool Strategy::DefaultWinningStrategy::isWinningStep(){
    vector<int> modifiedCell = b->getLastModifiedCell();
    if (modifiedCell[0] == -1)
    {
        return false;
    }
    vector<vector<Cell*>> cells = b->getCells();
    int r = cells.size();
    int c = cells[0].size();
    
//        check col wise
    int count = 0;
    int playerId = -1;
    int i = modifiedCell[0];
    for (int j = 0; j < c; j++)
    {
        if (cells[i][j]->isFilled())
        {
            int pId = cells[i][j]->getPlayer()->getId();
            if (playerId == -1 || playerId != pId)
            {
                count = 1;
                playerId = pId;
            } else {
                count++;
            }
            if (count == 4)
            {
                return true;
            }
        }
    }
    
//        check row wise
    count = 0;
    playerId = -1;
    i = modifiedCell[1];
    for (int j = 0; j < c; j++)
    {
        if (cells[j][i]->isFilled())
        {
            int pId = cells[j][i]->getPlayer()->getId();
            if (playerId == -1 || playerId != pId)
            {
                count = 1;
                playerId = pId;
            } else {
                count++;
            }
            if (count == 4)
            {
                return true;
            }
        }
    }
    
//        check diagonal 1
    int x = modifiedCell[0];
    int y = modifiedCell[1];
    while (x >= 0 && x < r && y >= 0 && y < c)
    {
        x--;
        y--;
    }
    x++;
    y++;
    count = 0;
    playerId = -1;
    while (x >= 0 && x < r && y >= 0 && y < c)
    {
        if (cells[x][y]->isFilled())
        {
            int pId = cells[x][y]->getPlayer()->getId();
            if (playerId == -1 || playerId != pId)
            {
                count = 1;
                playerId = pId;
            } else {
                count++;
            }
            if (count == 4)
            {
                return true;
            }
        }
        x++;
        y++;
    }
    
//        check diagonal 2
    x = modifiedCell[0];
    y = modifiedCell[1];
    while (x >= 0 && x < r && y >= 0 && y < c)
    {
        x++;
        y--;
    }
    x--;
    y++;
    count = 0;
    playerId = -1;
    while (x >= 0 && x < r && y >= 0 && y < c)
    {
        if (cells[x][y]->isFilled())
        {
            int pId = cells[x][y]->getPlayer()->getId();
            if (playerId == -1 || playerId != pId)
            {
                count = 1;
                playerId = pId;
            } else {
                count++;
            }
            if (count == 4)
            {
                return true;
            }
        }
        x--;
        y++;
    }
    
    return false;
}
