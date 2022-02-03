//
//  DefaultWinningStrategy.h
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#ifndef DefaultWinningStrategy_h
#define DefaultWinningStrategy_h

#include "WinningStrategy.h"
#include <iostream>
#include "../Models/Board.h"

using namespace std;
using namespace Models;

namespace Strategy {
class DefaultWinningStrategy: public WinningStrategy {
    Board *b;
public:
    DefaultWinningStrategy(Board *board)
    {
        b = board;
    }
    
    bool isWinningStep();
};
}

#endif /* DefaultWinningStrategy_h */
