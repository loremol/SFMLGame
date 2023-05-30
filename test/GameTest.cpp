#include "gtest/gtest.h"
#include "../src/Map/Map.h"

using namespace game;

TEST(Map, LoadMapFromFile
) {
game::Map map;
map.LoadMapFromFile("map.txt");
}

