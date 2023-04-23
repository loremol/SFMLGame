//
// Created by Lorenzo on 18/04/2023.
//

#ifndef SFMLGAME_WORLD_HPP
#define SFMLGAME_WORLD_HPP
#include <SFML/Graphics.hpp>
#include "../Map/Tile.hpp"
#include "../Definitions.hpp"
#include <vector>

namespace SFMLGame {
    class World {
    public:
// Matrix of GameTile pointers
        std::vector<std::vector<Tile *>> tiles;

        // Getter for gridLength
        int getGridLength() const {
            return gridLength;
        }

        // FIXME make grid length dependant on the map
        World(sf::Vector2i backgroundTileResolution, sf::Vector2i windowResolution);

    private:
        int gridLength;
        std::string resourcePath;
        FilePaths filePaths;
    };

}

#endif //SFMLGAME_WORLD_HPP
