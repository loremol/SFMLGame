//
// Created by Lorenzo on 19/04/2023.
//

#include "Player.hpp"

#include <utility>

namespace SFMLGame {
    Player::Player(GameDataRef data) : Entity(), velocity(100.f), data(std::move(data)) {
        SFMLGame::FilePaths filePaths;
        this->data->assets.LoadTexture("PlayerSprite", filePaths.PlayerSpritePath.make_preferred().string());
        this->sprite.setTexture(this->data->assets.GetTexture("PlayerSprite"));
        this->sprite.scale(1.0f, 1.0f);
    }

    void Player::move(float x_dir, float y_dir, float dt) {
        this->positionVector.x += x_dir * velocity * dt;
        this->positionVector.y += y_dir * velocity * dt;
        this->sprite.setPosition(positionVector.x, positionVector.y);
    }

    void Player::update(float dt) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this->move(0.f, -1.f, dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this->move(-1.f, 0.f, dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this->move(0.f, 1.f, dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->move(1.f, 0.f, dt);
    }

    void Player::draw() const {
        this->data->window.draw(this->sprite);
    }
}
