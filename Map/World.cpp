//
// Created by Lorenzo on 18/04/2023.
//

#include "World.hpp"

#include <utility>

namespace SFMLGame {
    World::World(GameDataRef dataRef, sf::Vector2f backgroundTileResolution) : data(std::move(dataRef)), gridLength(8) {
        tiles.clear();
        std::vector<Tile *> row;
        this->data->assets.LoadTexture("Floor", filePaths.GameFloorSpritePath.make_preferred().string());
        for (int i = 0; i < gridLength; i++) {
            for (int j = 0; j < gridLength; j++) {
                row.push_back(new Tile(this->data, "Floor",
                                       sf::Vector2f(static_cast<float>(i) * backgroundTileResolution.x,
                                                    static_cast<float>(j) * backgroundTileResolution.y)));
            }
            tiles.push_back(row);
            row.clear();
        }
    }
}