#ifndef REPLY_2022_CHARACTER_H
#define REPLY_2022_CHARACTER_H


class Character {
    int stamina;

public:
    virtual ~Character();
    explicit Character(int stamina);

public:
    int getStamina() const;
    void setStamina(int stamina);
};


#endif//REPLY_2022_CHARACTER_H
