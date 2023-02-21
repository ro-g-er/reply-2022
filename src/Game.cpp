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
    int tempStamina {};
    myFile >> tempStamina;
    pandora.setStamina(tempStamina);
    myFile >> maximumStamina;
    myFile >> turnsAvailable;
    myFile >> numDemons;
    std::string line;
    std::getline(myFile, line);
    int i{};
    while (std::getline(myFile, line)) {
        Demon d;
        d.read(line);
        d.setIndex(i);
        i++;
        demonsToFace.emplace_back(d);
    }
    myFile.close();
}

void Game::print() {
    std::cout << "Character Stamina: " << pandora.getStamina() << std::endl;
    std::cout << "Maximum Stamina:" << maximumStamina << std::endl;
    std::cout << "Turns Available: " << turnsAvailable << std::endl;
    std::cout << "Number of Demons: " << numDemons << std::endl;
    std::cout << "Demons to Face:" << std::endl;
    for (auto d: demonsToFace) {
        d.print();
    }
    std::cout << "Demons defeated:" << std::endl;
    for (auto d: demonsDefeated) {
        d.print();
    }
}

int Game::selectDemonToFace() {
    int indexDemonToFace{-1};
    for (int i = 0; i < demonsToFace.size(); i++) {
        if (demonsToFace[i].getStaminaConsumption() > pandora.getStamina()) {
            continue;
        }
        indexDemonToFace = i;
    }
    return indexDemonToFace;
}

void Game::faceDemon(int indexDemonToFace) {
    pandora.setStamina(pandora.getStamina() - demonsToFace.at(indexDemonToFace).getStaminaConsumption());
    int turnsRecover = demonsToFace.at(indexDemonToFace).getTurnsRecover();
    int staminaRecover = demonsToFace.at(indexDemonToFace).getStaminaRecover();
    turnsAndStaminaRecover.emplace_back(std::make_pair(turnsRecover, staminaRecover));
    //implement logic for fragments
    demonsDefeated.emplace_back(demonsToFace.at(indexDemonToFace));
    demonsToFace.erase(demonsToFace.begin()+indexDemonToFace);
}


void Game::logic() {
    for (int i = 0; i < turnsAvailable; i++) {
        int indexDemonToFace = selectDemonToFace();
        if (indexDemonToFace == -1) {
            continue;
        }
        faceDemon(indexDemonToFace);
    }
}
