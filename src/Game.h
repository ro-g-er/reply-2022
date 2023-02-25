#ifndef REPLY_2022_GAME_H
#define REPLY_2022_GAME_H

#include "Character.h"
#include "Demon.h"
#include <string>
#include <vector>

class Game {
    int maximumStamina;
    int turnsAvailable;
    int numDemons;
    Character pandora;
    std::vector<Demon> demonsToFace;
    std::vector<Demon> demonsDefeated;
    std::vector<std::pair<int, int>> turnsAndStaminaRecover;
    std::vector<std::queue<int>> fragments;

public:
    Game();
    virtual ~Game();
    void read(const std::string &nameFile);
    void print();
    void logic();
    void collectFragments();
    void write(const std::string &nameFile);

private:
    int selectDemonToFace();
    void faceDemon(int indexDemonToFace);
    void recoverStamina();
};


#endif//REPLY_2022_GAME_H
