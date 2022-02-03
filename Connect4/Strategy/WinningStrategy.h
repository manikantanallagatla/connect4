//
//  WinningStrategy.h
//  Connect4
//
//  Created by Nallagatla Manikanta on 01/02/22.
//

#ifndef WinningStrategy_h
#define WinningStrategy_h

namespace Strategy {
class WinningStrategy {
public:
    virtual bool isWinningStep() = 0;
};
}

#endif /* WinningStrategy_h */
