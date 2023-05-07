//
// Created by Lorenzo on 18/04/2023.
//

#ifndef SFMLGAME_TILE_HPP
#define SFMLGAME_TILE_HPP

#include <SFML/Graphics.h>
#include "../Game.h"

namespace SFMLGame {
    class Tile {
    public:
        Tile(GameDataRef, const std::string &spriteName, sf::Vector2f positionVector);

    public:
        sf::Vector2f pos;
        sf::Texture texture;
        sf::Sprite sprite;
        GameDataRef data;
    };

}

#endif //SFMLGAME_TILE_HPP
