#ifndef REPLY_2022_GAME_H
#define REPLY_2022_GAME_H

#include "Character.h"

class Game {
    int turnsAvailable;
    int turnsRecover;
    int numDemons;
    int numTurns;
    Character pandora;

public:
    int getTurnsAvailable() const;
    void setTurnsAvailable(int turnsAvailable);
    int getTurnsRecover() const;
    void setTurnsRecover(int turnsRecover);
    int getNumDemons() const;
    void setNumDemons(int numDemons);
    int getNumTurns() const;
    void setNumTurns(int numTurns);
};


#endif //REPLY_2022_GAME_H
