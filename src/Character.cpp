#include "Character.h"

int Character::getStamina() const {
    return stamina;
}
void Character::setStamina(int stamina) {
    Character::stamina = stamina;
}
Character::~Character() {
}
int Character::getFragmentsCollected() const {
    return fragmentsCollected;
}
void Character::setFragmentsCollected(int fragmentsCollected) {
    Character::fragmentsCollected = fragmentsCollected;
}
Character::Character() : stamina{}, fragmentsCollected{} {}
