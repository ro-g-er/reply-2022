#include "Demon.h"
#include <iostream>
#include <sstream>
#include <string>

Demon::Demon() : countFragments{} {}
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
void Demon::setNumberFragments(const std::queue<int> &numberFragments) {
    Demon::numberFragments = numberFragments;
}
const std::queue<int> &Demon::getNumberFragments() const {
    return numberFragments;
}
Demon::~Demon() {
}

void Demon::read(std::string textDemon, int numTurns) {
    int num;
    std::istringstream ss(textDemon);
    ss >> staminaConsumption >> turnsRecover >> staminaRecover >> turnsFragments;
    int count{};
    while (ss >> num && count < numTurns) {
        numberFragments.push(num);
        countFragments += num;
        count++;
    }
}

void Demon::print() {
    std::cout << "Stamina Consumption: " << staminaConsumption << std::endl;
    std::cout << "Turns to Recover: " << turnsRecover << std::endl;
    std::cout << "Stamina to Recover: " << staminaRecover << std::endl;
    std::cout << "Turns for Fragments: " << turnsFragments << std::endl;
    std::cout << "Number of Fragments: ";
    std::queue<int> tmpQueue = numberFragments;
    while (!tmpQueue.empty()) {
        std::cout << tmpQueue.front() << " ";
        tmpQueue.pop();
    }
    std::cout << std::endl;
}
int Demon::getIndex() const {
    return index;
}
void Demon::setIndex(int index) {
    Demon::index = index;
}
int Demon::getCountFragments() const {
    return countFragments;
}
void Demon::setCountFragments(int countFragments) {
    Demon::countFragments = countFragments;
}
