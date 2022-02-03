//
//  Board.cpp
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#include "Board.h"

using namespace Models;

vector<int> Board::getColWiseFreeRow()
{
    return colWiseFreeRow;
}

bool Board::setPlayer(int colIndex, Player*p)
{
    unique_lock<mutex> l(m);
    if (colIndex < 0 || colIndex >= cols)
        return false;
    int rowId = colWiseFreeRow[colIndex];
    if (rowId < 0)
        return false;
    cells[rowId][colIndex]->setPlayer(p);
    colWiseFreeRow[colIndex]--;
    lastModifiedRow = rowId;
    lastModifiedCol = colIndex;
    return true;
}

vector<vector<Cell*>> Board::getCells()
{
    return cells;
}

void Board::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cells[i][j]->isFilled() == false)
            {
                cout << "_";
            } else {
                cout << cells[i][j]->getPlayer()->getId();
            }
        }cout << endl;
    }
    cout << endl;
}

vector<int> Board::getLastModifiedCell()
{
    return {lastModifiedRow, lastModifiedCol};
}
