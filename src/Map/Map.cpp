#include <fstream>
#include <iostream>
#include "Map.h"

namespace game {
    Map::Map() {
//        for (int i = 0; i < gridLength; i++) {
//            for (int j = 0; j < gridLength; j++) {
//                row.push_back(new Tile("Floor", sf::Vector2f(static_cast<float>(i) * backgroundTileResolution.x,
//                                                             static_cast<float>(j) * backgroundTileResolution.y)));
//            }
//            tiles.push_back(row);
//            row.clear();
//        }
    }

    void Map::LoadMapFromFile(const std::string &fileName) {
        std::ifstream mapFile;
        std::string line, tileID;
        std::vector<Tile *> row;
        sf::Vector2f position(0, 0);
        mapFile.open(fileName, std::ios::in);

        if (mapFile.is_open()) {
            while (std::getline(mapFile, line)) {
                row.clear();
                std::stringstream stringStream(line);
                while (std::getline(stringStream, tileID, ',')) {
                    int ID = std::stoi(tileID);
                    row.push_back(new Tile(ID, position));
                    position.x += tileResolution;
                }
                tiles.push_back(row);
                position.x = 0;
                position.y += tileResolution;
            }
        }
        mapFile.close();
    }
}