#include "Game.h"
#include <iostream>

int main() {
    Game game;
    game.read("../input.txt");
    game.print();
    return 0;
}