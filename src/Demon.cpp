#include "Demon.h"
#include <iostream>
#include <sstream>
#include <string>

Demon::Demon() {}
int Demon::getStaminaConsumption() const {
    return staminaConsumption;
}
void Demon::setStaminaConsumption(int staminaConsumption) {
    Demon::staminaConsumption = staminaConsumption;
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
Demon::~Demon() {
}
const std::vector<int> &Demon::getNumberFragments() const {
    return numberFragments;
}
void Demon::setNumberFragments(const std::vector<int> &numberFragments) {
    Demon::numberFragments = numberFragments;
}

void Demon::read(std::string line) {
    int num;
    std::istringstream ss(line);
    ss >> staminaConsumption >> turnsRecover >> staminaRecover >> turnsFragments;
    while (ss >> num) {
        numberFragments.push_back(num);
    }
}

void Demon::print() {
    std::cout << "Stamina Consumption: " << staminaConsumption << std::endl;
    std::cout << "Turns to Recover: " << turnsRecover << std::endl;
    std::cout << "Stamina to Recover: " << staminaRecover << std::endl;
    std::cout << "Turns for Fragments: " << turnsFragments << std::endl;

    std::cout << "Number of Fragments: ";
    for (int i = 0; i < numberFragments.size(); i++) {
        std::cout << numberFragments[i] << " ";
    }
    std::cout << std::endl;
}
