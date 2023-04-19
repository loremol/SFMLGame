//
// Created by Lorenzo on 18/04/2023.
//

#include "GameWorld.h"
#if _WIN32
    std::string slash = R"(\)";
#endif
#if (__linux__)
    std::string slash = "/";
#endif

GameWorld::GameWorld(sf::Vector2i backgroundTileResolution, sf::Vector2i windowResolution, const std::string& resourcePath) : gridLength(windowResolution.x / backgroundTileResolution.x) {
    tiles.clear();
    std::string tilePath = resourcePath + "sprite" + slash + "tile" + slash;
    std::vector<GameTile *> row;

    for (int i = 0; i < gridLength; i++){
        for (int j = 0; j < gridLength; j++) {
            row.push_back(new GameTile(tilePath + "floor_1_64px.png", sf::Vector2i(i*backgroundTileResolution.x, j*backgroundTileResolution.y), backgroundTileResolution));
        }
        tiles.push_back(row);
        row.clear();
    }
}
