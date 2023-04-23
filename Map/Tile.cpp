//
// Created by Lorenzo on 18/04/2023.
//

#include "Tile.hpp"

namespace SFMLGame {
    bool Tile::setUpSprite(const std::string &texturePath, sf::Vector2i spriteResolution) {
        if (!texture.loadFromFile(texturePath)) {
            printf("Error in loading texture.\n");
            return false;
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, spriteResolution.x, spriteResolution.y));
        return true;
    }
}