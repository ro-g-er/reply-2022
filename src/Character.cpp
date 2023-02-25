#include "Character.h"

int Character::getStamina() const {
    return stamina;
}

void Character::setStamina(int s) {
    Character::stamina = s;
}

Character::~Character() = default;

int Character::getFragmentsCollected() const {
    return fragmentsCollected;
}

void Character::setFragmentsCollected(int fC) {
    Character::fragmentsCollected = fC;
}

Character::Character() : stamina{}, fragmentsCollected{} {}
