#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "../Definitions.h"
#include "../Entities/Entity.h"
#include <vector>

namespace game {
    class Map {
    public:
        explicit Map(const std::string &fileName);

        [[nodiscard]] std::vector<std::vector<Tile *>> getTileMatrix() const { return tiles; }

        [[nodiscard]] const std::vector<Entity *> &getEntities() const;

        [[nodiscard]] Entity *getPlayerPtr() const { return player; }

        void checkCollisions(float dt);


    private:
        std::vector<std::vector<Tile *>> tiles;
        Entity *player;
        std::vector<Entity *> entities;
        EntityFactory entityFactory;
        float tileResolution = 16.f;
        float tileScaling = 4.f;
    };
}

#endif //GAME_WORLD_HPP
