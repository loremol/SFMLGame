#ifndef GAME_TILE_HPP
#define GAME_TILE_HPP

#include <SFML/Graphics.hpp>
#include "../Init.h"

namespace game {
    class Tile {
    public:
        Tile(int id, sf::Vector2f position, float scale);

        sf::Sprite sprite;

        bool isWalkable() const;

    private:
        bool walkable;
    };
}

#endif //GAME_TILE_HPP
