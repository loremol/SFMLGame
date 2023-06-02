#include <fstream>
#include <iostream>
#include "Map.h"
#include "../Entities/Entity.h"

namespace game {
    Map::Map(const std::string &fileName) {
        std::ifstream mapFile;
        sf::Vector2f tilePosition(0, 0);
        mapFile.open(fileName, std::ios::in);

        if (mapFile.is_open()) {
            std::string line, tileID;
            std::vector<Tile *> row;
            while (std::getline(mapFile, line)) {
                row.clear();
                std::stringstream stringStream(line);
                while (std::getline(stringStream, tileID, ',')) {
                    row.push_back(new Tile(std::stoi(tileID), tilePosition, tileScaling));
                    tilePosition.x += tileResolution * tileScaling;
                }
                tiles.push_back(row);
                tilePosition.x = 0;
                tilePosition.y += tileResolution * tileScaling;
            }
        }
        sf::Vector2f playerPosition(160, 160);
        player = entityFactory.createEntity("Player", playerPosition);
        entities.push_back(player);
        mapFile.close();
    }

    void Map::checkCollisions(float dt) {
        for (auto &entity: entities) {
            sf::FloatRect entityPosition(entity->sprite.getGlobalBounds());
            sf::FloatRect nextPosition = entityPosition;
            sf::FloatRect testPosition = entityPosition;
            nextPosition.left += entity->movement.getVelocity().x * dt;
            nextPosition.top += entity->movement.getVelocity().y * dt;

            sf::FloatRect tileRect;

            for (auto &it: tiles) {
                for (auto &tile: it) {
                    tileRect = tile->sprite.getGlobalBounds();
                    if (!tile->isWalkable() && tileRect.intersects(nextPosition)) {
                        testPosition.left += entity->movement.getVelocity().x * dt;
                        if (tileRect.intersects(testPosition)) {
                            entity->movement.getVelocity().x = 0;
                        }

                        testPosition = entityPosition;

                        testPosition.top += entity->movement.getVelocity().y * dt;
                        if (tileRect.intersects(testPosition)) {
                            entity->movement.getVelocity().y = 0;
                        }

                        testPosition = entityPosition;
                    }
                }
            }
        }
    }

    const std::vector<Entity *> &Map::getEntities() const {
        return entities;
    }
}