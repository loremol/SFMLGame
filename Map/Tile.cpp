//
// Created by Lorenzo on 18/04/2023.
//

#include "Tile.hpp"

#include <utility>

namespace SFMLGame {
    Tile::Tile(GameDataRef dataRef, const std::string &spriteName, sf::Vector2f positionVector) : data(
            std::move(dataRef)), pos(positionVector) {
        this->texture = this->data->assets.GetTexture(spriteName);
        this->texture.setSmooth(true);
        this->sprite.setTexture(this->texture);
        this->sprite.setTexture(texture);
        this->sprite.setPosition(positionVector.x, positionVector.y);
    }
}