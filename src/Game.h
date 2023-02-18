#ifndef REPLY_2022_GAME_H
#define REPLY_2022_GAME_H

#include "Character.h"
#include "Demon.h"
#include <string>
#include <vector>

class Game {
    int initialCharacterStamina;
    int maximumStamina;
    int turnsAvailable;
    int numDemons;
    Character pandora;
    std::vector<Demon> demons;

public:
    Game();
    virtual ~Game();
    int getTurnsAvailable() const;
    void setTurnsAvailable(int turnsAvailable);
    int getInitialCharacterStamina() const;
    void setInitialCharacterStamina(int initialCharacterStamina);
    int getMaximumStamina() const;
    void setMaximumStamina(int maximumStamina);
    int getNumDemons() const;
    void setNumDemons(int numDemons);
    void read(std::string nameFile);
    void print();
};


#endif //REPLY_2022_GAME_H