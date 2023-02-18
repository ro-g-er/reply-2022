#include "Game.h"

int Game::getTurnsAvailable() const {
    return turnsAvailable;
}
void Game::setTurnsAvailable(int turnsAvailable) {
    Game::turnsAvailable = turnsAvailable;
}
int Game::getTurnsRecover() const {
    return turnsRecover;
}
void Game::setTurnsRecover(int turnsRecover) {
    Game::turnsRecover = turnsRecover;
}
int Game::getNumDemons() const {
    return numDemons;
}
void Game::setNumDemons(int numDemons) {
    Game::numDemons = numDemons;
}
int Game::getNumTurns() const {
    return numTurns;
}
void Game::setNumTurns(int numTurns) {
    Game::numTurns = numTurns;
}
