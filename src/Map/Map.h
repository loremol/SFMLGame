#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Definitions.h"
#include <vector>

namespace game {
    class Map {
    public:
        void LoadMapFromFile(const std::string &fileName);

        std::vector<std::vector<Tile *>> tiles;

        Map();

        ~Map() = default;

    private:
        float tileResolution = 64.f;
    };
}

#endif //GAME_WORLD_HPP
