#ifndef GAME_TILE_HPP
#define GAME_TILE_HPP

#include <SFML/Graphics.hpp>
#include "../Init.h"

namespace game {
    class Tile {
    public:
        Tile(int id, sf::Vector2f position);

        sf::Sprite sprite;
        sf::Vector2i position;
        int textureID;
        bool isWalkable = true;
        bool isAnimated = false;
    private:
        std::string tileAssetNames[2] = {"Floor", "Grass"};

    };

}

#endif //GAME_TILE_HPP
