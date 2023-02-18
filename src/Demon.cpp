#include "Demon.h"

Demon::Demon() {}
int Demon::getStaminaComsumption() const {
    return staminaComsumption;
}
void Demon::setStaminaComsumption(int staminaComsumption) {
    Demon::staminaComsumption = staminaComsumption;
}
int Demon::getTurnsRecover() const {
    return turnsRecover;
}
void Demon::setTurnsRecover(int turnsRecover) {
    Demon::turnsRecover = turnsRecover;
}
int Demon::getStaminaRecover() const {
    return staminaRecover;
}
void Demon::setStaminaRecover(int staminaRecover) {
    Demon::staminaRecover = staminaRecover;
}
int Demon::getTurnsFragments() const {
    return turnsFragments;
}
void Demon::setTurnsFragments(int turnsFragments) {
    Demon::turnsFragments = turnsFragments;
}
int Demon::getNumberFragments() const {
    return numberFragments;
}
void Demon::setNumberFragments(int numberFragments) {
    Demon::numberFragments = numberFragments;
}
Demon::~Demon() {
}
