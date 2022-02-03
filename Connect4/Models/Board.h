//
//  Board.h
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#ifndef Board_h
#define Board_h

#include "Cell.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <mutex>

using namespace std;

namespace Models {
class Board {
    vector<vector<Cell*>> cells;
    vector<int> colWiseFreeRow;
    int rows;
    int cols;
    int lastModifiedRow;
    int lastModifiedCol;
    mutex m;
public:
    Board(int r, int c)
    {
        rows = r;
        cols = c;
        lastModifiedRow = lastModifiedCol = -1;
        int cellId = 1;
        for (int i = 0; i < r; i++)
        {
            vector<Cell*> temp;
            for (int j = 0; j < c; j++)
            {
                temp.push_back(new Cell(cellId++));
            }
            cells.push_back(temp);
        }
        for (int i = 0; i < c; i++)
        {
            colWiseFreeRow.push_back(r - 1);
        }
    }
    
    vector<int> getColWiseFreeRow();
    
    bool setPlayer(int colIndex, Player*p);
    
    vector<vector<Cell*>> getCells();
    
    void print();
    
    vector<int> getLastModifiedCell();
};
}

#endif /* Board_h */
