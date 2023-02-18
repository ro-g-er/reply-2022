#ifndef REPLY_2022_GAME_H
#define REPLY_2022_GAME_H

#include "Character.h"
#include "Demon.h"
#include <vector>

class Game {
    int turnsAvailable;
    int turnsRecover;
    int numDemons;
    int numTurns;
    Character pandora;
    std::vector<Demon> Demons;

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
