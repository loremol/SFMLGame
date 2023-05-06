//
// Created by Lorenzo on 19/04/2023.
//
#include "Entity.hpp"

#include <utility>

namespace SFMLGame {
    Entity::Entity(GameDataRef dataRef, const float &maxVel, const float &acc, const float &dec, std::string sprite) : data(std::move(dataRef)),
                                                                                  spriteName(std::move(sprite)),
                                                                                  maxVelocity(maxVel),
                                                                                  movementComponent(this->sprite,maxVel,acc,dec) {
    }

    void Entity::update(const float &dt) {
        this->movementComponent.update(dt);
    }

    void Entity::render() {
        this->data->window.draw(this->sprite);
    }

    void Entity::setPosition(const float &x, const float &y) {
        this->sprite.setPosition(x, y);
    }

    void Entity::setSprite(const std::string &name) {
        this->texture = sf::Texture(this->data->assets.GetTexture(name));
        this->sprite.setTexture(texture);
    }

    void Entity::move(const float dir_x, const float dir_y, const float &dt) {
        this->movementComponent.move(dir_x, dir_y, dt); // sets velocity
    }
}

