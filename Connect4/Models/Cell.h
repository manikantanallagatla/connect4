//
//  Cell.h
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#ifndef Cell_h
#define Cell_h

#include "Player.h"

namespace Models {
class Cell {
    int cellId;
    Player *p;
public:
    Cell(int cid)
    {
        cellId = cid;
        p = NULL;
    }
    int getId()
    {
        return cellId;
    }
    bool isFilled()
    {
        return p != NULL;
    }
    Player *getPlayer()
    {
        return p;
    }
    int setPlayer(Player *pl)
    {
        if (p == NULL)
        {
            p = pl;
            return true;
        }
//        Exceptions here
        return false;
    }
};
}

#endif /* Cell_h */
