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
    int getStaminaConsumption() const;
    void setStaminaConsumption(int staminaConsumption);
    int getTurnsRecover() const;
    void setTurnsRecover(int turnsRecover);
    int getStaminaRecover() const;
    void setStaminaRecover(int staminaRecover);
    int getTurnsFragments() const;
    void setTurnsFragments(int turnsFragments);
    void read(std::string textDemon, int numTurns);
    void print();
    int getIndex() const;
    void setIndex(int index);
    void setNumberFragments(const std::queue<int> &numberFragments);
    const std::queue<int> &getNumberFragments() const;
    int getCountFragments() const;
    void setCountFragments(int countFragments);
};


#endif//REPLY_2022_DEMON_H
