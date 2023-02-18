#include "Game.h"
#include "Demon.h"
#include <fstream>
#include <iostream>

int Game::getTurnsAvailable() const {
    return turnsAvailable;
}
void Game::setTurnsAvailable(int turnsAvailable) {
    Game::turnsAvailable = turnsAvailable;
}
Game::Game() {}

Game::~Game() {
}
int Game::getInitialCharacterStamina() const {
    return initialCharacterStamina;
}
void Game::setInitialCharacterStamina(int initialCharacterStamina) {
    Game::initialCharacterStamina = initialCharacterStamina;
}
int Game::getMaximumStamina() const {
    return maximumStamina;
}
void Game::setMaximumStamina(int maximumStamina) {
    Game::maximumStamina = maximumStamina;
}
int Game::getNumDemons() const {
    return numDemons;
}
void Game::setNumDemons(int numDemons) {
    Game::numDemons = numDemons;
}

void Game::read(std::string nameFile) {
    std::ifstream myFile;
    myFile.open(nameFile, std::ios::in);
    if (!myFile.is_open()) {
        std::cout << "Reading of" << nameFile << "failed";
        return;
    }
    myFile >> initialCharacterStamina;
    myFile >> maximumStamina;
    myFile >> turnsAvailable;
    myFile >> numDemons;
    std::string line;
    std::getline(myFile, line);
    while (std::getline(myFile, line)) {
        Demon d;
        d.read(line);
        demons.emplace_back(d);
    }
    myFile.close();
}

void Game::print() {
    std::cout << "Initial Character Stamina: " << initialCharacterStamina << std::endl;
    std::cout << "Maximum Stamina:" << maximumStamina << std::endl;
    std::cout << "Turns Available: " << turnsAvailable << std::endl;
    std::cout << "Number of Demons: " << numDemons << std::endl;
    for (auto d: demons) {
        d.print();
    }
}
