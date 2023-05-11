//
// Created by Lorenzo on 19/04/2023.
//

#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "../Components/MovementComponent.h"
#include "../Init.h"

namespace game {
    class Entity {
    public:
        Entity(const float &maxVel, const float &acc, const float &dec, const std::string &spriteName);

        virtual ~Entity() = default;

        virtual void move(float dir_x, float dir_y);

        virtual void update(const float &dt);

        virtual void render();

        sf::Vector2f positionVector;

    protected:
        std::string spriteName;
        MovementComponent movementComponent;
    };

}

#endif //GAME_ENTITY_HPP
