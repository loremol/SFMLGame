//
// Created by Lorenzo on 18/04/2023.
//

#ifndef SFMLGAME_WORLD_HPP
#define SFMLGAME_WORLD_HPP

#include <SFML/Graphics.h>
#include "Tile.h"
#include "../Definitions.h"
#include <vector>

namespace SFMLGame {
    class World {
    public:
        // Matrix of GameTile pointers
        std::vector<std::vector<Tile *>> tiles;

        // FIXME make grid length dependant on the map
        World(GameDataRef dataRef, sf::Vector2f backgroundTileResolution);

        int gridLength;

    private:
        GameDataRef data;
        std::string resourcePath;
        FilePaths filePaths;
    };

}

#endif //SFMLGAME_WORLD_HPP
