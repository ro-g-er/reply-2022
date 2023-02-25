#include "Game.h"
#include <iostream>

int main(int argc, char **argv) {
    Game game;
    if (argc != 3) {
        std::cout << "Number of parameters must be equal to 2 (input output respectively)" << std::endl;
    } else {
        game.read(argv[1]);
        game.logic();
        game.print();
        game.write(argv[2]);
    }
    return 0;
}