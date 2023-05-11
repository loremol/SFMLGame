//
// Created by Lorenzo on 18/04/2023.
//

#ifndef GAME_TILE_HPP
#define GAME_TILE_HPP

#include <SFML/Graphics.hpp>
#include "../Init.h"

namespace game {
    class Tile {
    public:
        Tile(const std::string &spriteName, sf::Vector2f positionVector);

    public:
        sf::Texture texture;
        sf::Sprite sprite;
    };

}

#endif //GAME_TILE_HPP
