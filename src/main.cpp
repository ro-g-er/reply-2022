#include "Game.h"
#include <iostream>

int main(int argc, char **argv) {
    Game game;
    if (argc != 2) {
        std::cout << "Number of parameters must be equal to 1" << std::endl;
    } else {
        game.read(argv[1]);
        game.print();
    }
    return 0;
}