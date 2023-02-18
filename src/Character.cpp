#include "Character.h"

int Character::getStamina() const {
    return stamina;
}
void Character::setStamina(int stamina) {
    Character::stamina = stamina;
}
Character::~Character() {
}
Character::Character(int stamina) : stamina(stamina) {}
