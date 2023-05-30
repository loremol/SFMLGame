#include "Tile.h"
#include "Map.h"
#include "../mgr.h"

namespace game {
    Tile::Tile(const int id, sf::Vector2f position) {
        sprite.setTexture(mgr::assets.GetTexture(tileAssetNames[id]));
        sprite.setPosition(position.x, position.y);
    }
}