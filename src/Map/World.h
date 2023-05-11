//
// Created by Lorenzo on 18/04/2023.
//

#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Definitions.h"
#include <vector>

namespace game {
    class World {
    public:
        // Matrix of GameTile pointers
        std::vector<std::vector<Tile *>> tiles;

        // FIXME make grid length dependant on the map
        explicit World(sf::Vector2f backgroundTileResolution);

        int gridLength;

    private:
        std::string resourcePath;
    };

}

#endif //GAME_WORLD_HPP
