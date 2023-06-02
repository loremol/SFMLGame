#include "Tile.h"
#include "../mgr.h"

namespace game {
    Tile::Tile(const int id, sf::Vector2f position, float scale) {
        switch (id) {
            case 0:
                walkable = true;
                break;
            case 1:
                walkable = false;
                break;

            default:
                walkable = false;
        }
        std::string textureName = mgr::assets.textureID[id];
        sprite.setTexture(mgr::assets.getTexture(textureName));
        sprite.setPosition(position.x, position.y);
        sprite.scale(scale, scale);
    }

    bool Tile::isWalkable() const {
        return walkable;
    }
}