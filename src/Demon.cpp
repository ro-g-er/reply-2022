#include "Demon.h"
#include <iostream>
#include <sstream>
#include <string>

Demon::Demon() : staminaConsumption{}, turnsRecover{}, turnsFragments{}, staminaRecover{}, index{}, countFragments{} {}

int Demon::getStaminaConsumption() const {
    return staminaConsumption;
}

int Demon::getTurnsRecover() const {
    return turnsRecover;
}

int Demon::getStaminaRecover() const {
    return staminaRecover;
}

const std::queue<int> &Demon::getNumberFragments() const {
    return numberFragments;
}

Demon::~Demon() = default;

void Demon::read(const std::string &textDemon, int numTurns) {
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

void Demon::setIndex(int i) {
    Demon::index = i;
}

int Demon::getCountFragments() const {
    return countFragments;
}
