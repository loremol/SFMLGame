//
// Created by Lorenzo on 18/04/2023.
//
#include <SFML/Graphics.hpp>
#include "GameTile.h"
#include <vector>

#ifndef SFMLTEST_GAMEWORLD_H
#define SFMLTEST_GAMEWORLD_H

class GameWorld {
public:
    // Matrix of GameTile pointers
    std::vector<std::vector<GameTile *>> tiles;

    // Getter for gridLength
    [[nodiscard]] int getGridLength() const {
        return gridLength;
    }

    GameWorld(sf::Vector2i backgroundTileResolution, sf::Vector2i windowResolution);

private:
    int gridLength;
};

#endif //SFMLTEST_GAMEWORLD_H
