//
// Created by Lorenzo on 18/04/2023.
//

#include "World.hpp"

namespace SFMLGame {
    World::World(sf::Vector2i backgroundTileResolution, sf::Vector2i windowResolution) : gridLength(
            windowResolution.x / backgroundTileResolution.x) {
        tiles.clear();
        std::vector<Tile *> row;

        for (int i = 0; i < gridLength; i++) {
            for (int j = 0; j < gridLength; j++) {
                row.push_back(new Tile(filePaths.GameFloorSpritePath.make_preferred().string(),
                                       sf::Vector2i(i * backgroundTileResolution.x, j * backgroundTileResolution.y),
                                       backgroundTileResolution));
            }
            tiles.push_back(row);
            row.clear();
        }
    }
}