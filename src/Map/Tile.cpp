//
// Created by Lorenzo on 18/04/2023.
//

#include "Tile.h"
#include "../mgr.h"

namespace game {
    Tile::Tile(const std::string &spriteName, sf::Vector2f positionVector) {
        sprite.setTexture(mgr::assets.GetTexture(spriteName));
        sprite.setPosition(positionVector.x, positionVector.y);
    }
}