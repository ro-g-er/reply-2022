#ifndef REPLY_2022_DEMON_H
#define REPLY_2022_DEMON_H


class Demon {
    int staminaConsumption;
    int turnsRecover;
    int staminaRecover;
    int turnsFragments;
    int numberFragments;

public:
    Demon();
    virtual ~Demon();
    int getStaminaComsumption() const;
    void setStaminaComsumption(int staminaComsumption);
    int getTurnsRecover() const;
    void setTurnsRecover(int turnsRecover);
    int getStaminaRecover() const;
    void setStaminaRecover(int staminaRecover);
    int getTurnsFragments() const;
    void setTurnsFragments(int turnsFragments);
    int getNumberFragments() const;
    void setNumberFragments(int numberFragments);
};


#endif//REPLY_2022_DEMON_H
