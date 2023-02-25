#ifndef REPLY_2022_CHARACTER_H
#define REPLY_2022_CHARACTER_H


class Character {
    int stamina;
    int fragmentsCollected;

public:
    Character();
    virtual ~Character();
    [[nodiscard]] int getStamina() const;
    void setStamina(int s);
    [[nodiscard]] int getFragmentsCollected() const;
    void setFragmentsCollected(int fC);
};


#endif//REPLY_2022_CHARACTER_H
