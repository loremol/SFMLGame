//
// Created by Lorenzo on 19/04/2023.
//

#include "Player.hpp"
#include <cmath>
#include <utility>

namespace SFMLGame {
    // 150, 15, 10
    Player::Player(GameDataRef data, float x, float y) : Entity(std::move(data), 250.f, 15.f, 7.5f,"PlayerSprite") {
        SFMLGame::FilePaths filePaths;
        this->setSprite(this->spriteName);
        this->setPosition(x, y);
    }
}
