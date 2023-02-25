#ifndef REPLY_2022_CHARACTER_H
#define REPLY_2022_CHARACTER_H


class Character {
    int stamina;
    int fragmentsCollected;

public:
    Character();
    virtual ~Character();
    int getStamina() const;
    void setStamina(int stamina);
    int getFragmentsCollected() const;
    void setFragmentsCollected(int fragmentsCollected);
};


#endif//REPLY_2022_CHARACTER_H
