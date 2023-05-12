//
// Created by Lorenzo on 18/04/2023.
//

#ifndef GAME_TILE_HPP
#define GAME_TILE_HPP

#include <SFML/Graphics.hpp>
#include "../Init.h"

namespace game {
    enum tileIDs : unsigned int {
        floor = 1
    };

    class Tile {
    public:
        Tile(const std::string &spriteName, sf::Vector2f position);

        sf::Sprite sprite;
        sf::Vector2i position;
        int textureID;
        bool isWalkable = true;
        bool isAnimated = false;
    };

}

#endif //GAME_TILE_HPP
