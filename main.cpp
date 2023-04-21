#include "Definitions.hpp"
#include "Game.hpp"

// 1. User interaction
// 2. Update game state
// 3. Draw to the screen

int main() {
    SFMLGame::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game");
    return EXIT_SUCCESS;
}

