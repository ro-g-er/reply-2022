#ifndef REPLY_2022_DEMON_H
#define REPLY_2022_DEMON_H

#include <string>
#include <vector>

class Demon {
    int staminaConsumption;
    int turnsRecover;
    int staminaRecover;
    int turnsFragments;
    std::vector<int> numberFragments;

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
    const std::vector<int> &getNumberFragments() const;
    void setNumberFragments(const std::vector<int> &numberFragments);
    void read(std::string line);
    void print();
};


#endif//REPLY_2022_DEMON_H
