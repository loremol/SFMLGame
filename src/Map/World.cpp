#include "World.h"

namespace game {
    World::World(sf::Vector2f backgroundTileResolution) : gridLength(20) {
        tiles.clear();
        std::vector<Tile *> row;
        for (int i = 0; i < gridLength; i++) {
            for (int j = 0; j < gridLength; j++) {
                row.push_back(new Tile("Floor", sf::Vector2f(static_cast<float>(i) * backgroundTileResolution.x,
                                                             static_cast<float>(j) * backgroundTileResolution.y)));
            }
            tiles.push_back(row);
            row.clear();
        }
    }
}