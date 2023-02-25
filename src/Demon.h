#ifndef REPLY_2022_DEMON_H
#define REPLY_2022_DEMON_H

#include <queue>
#include <string>

class Demon {
    int staminaConsumption;
    int turnsRecover;
    int staminaRecover;
    int turnsFragments;
    std::queue<int> numberFragments;
    int index;
    int countFragments;

public:
    Demon();
    virtual ~Demon();
    [[nodiscard]] int getStaminaConsumption() const;
    [[nodiscard]] int getTurnsRecover() const;
    [[nodiscard]] int getStaminaRecover() const;
    void read(const std::string& textDemon, int numTurns);
    void print();
    [[nodiscard]] int getIndex() const;
    void setIndex(int i);
    [[nodiscard]] const std::queue<int> &getNumberFragments() const;
    [[nodiscard]] int getCountFragments() const;
};


#endif//REPLY_2022_DEMON_H
