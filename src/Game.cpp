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
        std::cout << "Reading of " << nameFile << "failed";
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
        d.read(line, turnsAvailable);
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
    int max{};
    for (int i{}; i < demonsToFace.size(); i++) {
        if (demonsToFace[i].getStaminaConsumption() > pandora.getStamina()) {
            continue;
        }
        if (max < demonsToFace.at(i).getCountFragments()) {
            indexDemonToFace = i;
            max = demonsToFace.at(i).getCountFragments();
        }
    }
    return indexDemonToFace;
}

void Game::faceDemon(int indexDemonToFace) {
    pandora.setStamina(pandora.getStamina() - demonsToFace.at(indexDemonToFace).getStaminaConsumption());
    int turnsRecover = demonsToFace.at(indexDemonToFace).getTurnsRecover();
    int staminaRecover = demonsToFace.at(indexDemonToFace).getStaminaRecover();
    turnsAndStaminaRecover.emplace_back(std::make_pair(turnsRecover, staminaRecover));
    fragments.push_back(demonsToFace.at(indexDemonToFace).getNumberFragments());
    demonsDefeated.emplace_back(demonsToFace.at(indexDemonToFace));
    demonsToFace.erase(demonsToFace.begin() + indexDemonToFace);
}

void Game::collectFragments() {
    for (int i{}; i < fragments.size(); i++) {
        pandora.setFragmentsCollected(pandora.getFragmentsCollected() + fragments.at(i).front());
        fragments.at(i).pop();
    }
    fragments.erase(std::remove_if(fragments.begin(), fragments.end(), [](std::queue<int> q) { return q.empty(); }), fragments.end());
}

void Game::logic() {
    for (int i{}; i < turnsAvailable; i++) {
        recoverStamina();
        int indexDemonToFace = selectDemonToFace();
        if (indexDemonToFace == -1) {
            collectFragments();
            continue;
        }
        faceDemon(indexDemonToFace);
        collectFragments();
    }
    std::cout << "Fragments collected: " << pandora.getFragmentsCollected() << std::endl;
}

void Game::recoverStamina() {
    for (int i = 0; i<turnsAndStaminaRecover.size(); i++) {
        turnsAndStaminaRecover[i].first--;
        if (turnsAndStaminaRecover[i].first==0){
            pandora.setStamina(pandora.getStamina()+turnsAndStaminaRecover[i].second);
        }
    }
}

void Game::write(std::string nameFile) {
    std::ofstream myFile;
    myFile.open(nameFile, std::ios::out);
    if (!myFile.is_open()) {
        std::cout << "Writing to " << nameFile << "failed";
        return;
    }
    for (auto d : demonsDefeated) {
        myFile << d.getIndex() << std::endl;
    }
    for (auto d : demonsToFace) {
        myFile << d.getIndex() << std::endl;
    }
    myFile.close();
}
