#ifndef REPLY_2022_CHARACTER_H
#define REPLY_2022_CHARACTER_H


class Character {
    int stamina;

public:
    Character();
    virtual ~Character();
    int getStamina() const;
    void setStamina(int stamina);
};


#endif//REPLY_2022_CHARACTER_H
